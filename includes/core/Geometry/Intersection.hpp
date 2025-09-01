#pragma once
#include "Point.hpp"
#include "../Core.hpp"
#include "../Vectors/Vector2.hpp"
#include "../Vectors/Vector3.hpp"
#include "../Vectors/VectorBase.hpp"
#include "GeoUtils.hpp"

typedef RELATIVE_POSITION Position;

    template<typename T>
    bool hasIntersection(const Point2D<T>& a, const Point2D<T>& b, const Point2D<T>& c, const Point2D<T>& d) {
        Position AB_C = relativePosition2D(a, b, c);
        Position AB_D = relativePosition2D(a, b, d);
        Position CD_A = relativePosition2D(c, d, a);
        Position CD_B = relativePosition2D(c, d, b);

        if(AB_C == Position::ORIGIN || AB_C == Position::DESTINATION || AB_C == Position::BETWEEN)
            return true;

        if(AB_D == Position::ORIGIN || AB_D == Position::DESTINATION || AB_D == Position::BETWEEN)
            return true;

        if(CD_A == Position::ORIGIN || CD_A == Position::DESTINATION || CD_A == Position::BETWEEN)
            return true;

        if(CD_B == Position::ORIGIN || CD_B == Position::DESTINATION || CD_B == Position::BETWEEN)
            return true;

        return customXor(AB_C == Position::LEFT, AB_D == Position::LEFT) && customXor(CD_A == Position::LEFT, CD_B == Position::LEFT);
    }

    /**
     * @brief Calcule le point d'intersection entre deux droites définies par les segments [AB] et [CD].
     *
     * Cette fonction prend quatre points (A, B, C, D) et détermine le point d'intersection
     * de la droite passant par A et B avec la droite passant par C et D.
     *
     * @tparam T Type numérique utilisé pour les coordonnées (int, float, double, etc.).
     * @return Point2D<T> Le point d'intersection unique entre les deux droites.
     *
     * @note La fonction utilise une assertion si les droites sont parallèles ou collinéaires
     *       (cas où l'intersection n'est pas définie de manière unique).
     */
    template<typename T>
    Point2D<T> intersection(const Point2D<T>& a, const Point2D<T>& b, const Point2D<T>& c, const Point2D<T>& d) {
        // p(t) = A + t(AB)
        // n(X - C) = 0
        //-----------------------
        // n(A + t(AB) - C) = 0
        // n(A - C) + nt(AB) = 0
        // nt(AB) = -n(A - C)
        // t = -n(A - C) / n(AB)

        Vector2<T> AB = Vector2(b.x - a.x, b.y - a.y);
        Vector2<T> CA = Vector2(a.x - c.x, a.y - c.y);
        Vector2<T> CD = Vector2(d.x - c.x, d.y - c.y);

        Vector2<T> n = Vector2(CD.Y(), -CD.X());
        T denominator = dotProduct(n, AB);

        assert(denominator != 0 && "The line AB & CD are parallel or colinear.");

        T t = -dotProduct(n, CA) / denominator;

        Vector2<T> result = Vector2<T>(a.x, a.y) + (t * AB);

        return Point2D(result.X(), result.Y());
    }
