//
// Created by tategotoazarasi on 2021/12/28.
//

#ifndef PROBLEMSCPP_ACWING_H
#define PROBLEMSCPP_ACWING_H

#include<iostream>
#include <set>
#include <unordered_set>
#include<vector>

using namespace std;

namespace acwing {
    class acwing1 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing4200 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing4201 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing610 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing604 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing606 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing609 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing615 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing616 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing653 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing4203 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing4204 {
    public:
        static int main(istream &, ostream &);
    };

    class acwing2058 {
    public:
        static int main(istream &, ostream &);
    };

    /**
     * \brief 时间转换
     */
    class acwing654 {
    public:
        static int main(istream &, ostream &);
    };

    /**
     * \brief 简单乘积
     */
    class acwing605 {
    public:
        static int main(istream &, ostream &);
    };

    /**
     * \brief AcWing 2041. 干草堆
     */
    class acwing2041 {
    public:
        static int main(istream &, ostream &);
    };

    /**
     * \brief AcWing 2060. 奶牛选美
     */
    namespace acwing2060 {
        class acwing2060 {
        public:
            static int main(istream &, ostream &);
        };


        struct point {
            int x;
            int y;

            point() = default;

            point(int x, int y) : x(x), y(y) {};
        };

        struct pointhash {
            size_t operator()(const point &) const;
        };

        struct pointequal {
            bool operator()(const point &, const point &) const;
        };

        void flood(point, bool[55][55], unordered_set<point, pointhash, pointequal> *, char[55][55], int, int);
    }

    /**
     * \brief AcWing 2019. 拖拉机
     */
    namespace acwing2019 {
        const int N = 1000;

        struct point {
            int x;
            int y;
            int step;

            point(int x, int y, int step) : x(x), y(y), step(step) {};
        };

        int bfs(point, int[1010][1010], int, int);

        class acwing2019 {
        public:
            static int main(istream &, ostream &);
        };
    }
}
#endif //PROBLEMSCPP_ACWING_H
