//
// Created by tategotoazarasi on 2022/1/7.
//
#include "acwing.h"
#include "gtest/gtest.h"
#include <vector>

namespace acwing {
	TEST(acwing1, case1) {
		istringstream in("3 4");
		auto out = ostringstream();
		acwing1::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing4200, case1) {
		istringstream in("2 7 1 8 2 8");
		auto out = ostringstream();
		acwing4200::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(acwing4200, case2) {
		istringstream in("20 30 40 50 0 100");
		auto out = ostringstream();
		acwing4200::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("20", ans);
	}

	TEST(acwing4200, case3) {
		istringstream in("31 41 59 26 17 43");
		auto out = ostringstream();
		acwing4200::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("9", ans);
	}

	TEST(acwing4201, case1) {
		istringstream in("10");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing4201, case2) {
		istringstream in("20");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing4201, case3) {
		istringstream in("100");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing4201, case4) {
		istringstream in("1000");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("8", ans);
	}

	TEST(acwing4201, case5) {
		istringstream in("10000");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("16", ans);
	}

	TEST(acwing4201, case6) {
		istringstream in("200");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing4201, case7) {
		istringstream in("101");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(acwing4201, case8) {
		istringstream in("1");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing4201, case9) {
		istringstream in("102");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(acwing4201, case10) {
		istringstream in("111");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing4201, case11) {
		istringstream in("110");
		auto out = ostringstream();
		acwing4201::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing608, case1) {
		istringstream in("5\n6\n7\n8");
		auto out = ostringstream();
		acwing608::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("DIFERENCA = -26", ans);
	}

	TEST(acwing604, case1) {
		istringstream in("2.00");
		auto out = ostringstream();
		acwing604::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("A=12.5664", ans);
	}

	TEST(acwing606, case1) {
		istringstream in("5.0\n7.1");
		auto out = ostringstream();
		acwing606::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("MEDIA = 6.43182", ans);
	}

	TEST(acwing609, case1) {
		istringstream in("25\n100\n5.50");
		auto out = ostringstream();
		acwing609::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("NUMBER = 25\n"
		          "SALARY = U$ 550.00",
		          ans);
	}

	TEST(acwing615, case1) {
		istringstream in("500\n35.0");
		auto out = ostringstream();
		acwing615::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("14.286 km/l", ans);
	}

	TEST(acwing616, case1) {
		istringstream in("1.0 7.0\n5.0 9.0");
		auto out = ostringstream();
		acwing616::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("4.4721", ans);
	}

	TEST(acwing653, case1) {
		istringstream in("576");
		auto out = ostringstream();
		acwing653::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("576\n"
		          "5 nota(s) de R$ 100,00\n"
		          "1 nota(s) de R$ 50,00\n"
		          "1 nota(s) de R$ 20,00\n"
		          "0 nota(s) de R$ 10,00\n"
		          "1 nota(s) de R$ 5,00\n"
		          "0 nota(s) de R$ 2,00\n"
		          "1 nota(s) de R$ 1,00",
		          ans);
	}

	TEST(acwing4203, case1) {
		istringstream in("001001");
		auto out = ostringstream();
		acwing4203::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("NO", ans);
	}

	TEST(acwing4203, case2) {
		istringstream in("1000000001");
		auto out = ostringstream();
		acwing4203::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("YES", ans);
	}

	TEST(acwing4204, case1) {
		istringstream in("2");
		auto out = ostringstream();
		acwing4204::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0 1\n"
		          "1 0",
		          ans);
	}

	TEST(acwing4204, case2) {
		istringstream in("4");
		auto out = ostringstream();
		acwing4204::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0 1 2 3\n"
		          "1 0 3 2\n"
		          "2 3 0 1\n"
		          "3 2 1 0",
		          ans);
	}

	TEST(acwing4204, case3) {
		istringstream in("6");
		auto out = ostringstream();
		acwing4204::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0 1 2 3 4 5\n"
		          "1 0 3 4 5 2\n"
		          "2 3 0 5 1 4\n"
		          "3 4 5 0 2 1\n"
		          "4 5 1 2 0 3\n"
		          "5 2 4 1 3 0",
		          ans);
	}

	TEST(acwing2058, case1) {
		istringstream in("1010\n"
		                 "212");
		auto out = ostringstream();
		acwing2058::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("14", ans);
	}

	TEST(acwing654, case1) {
		istringstream in("556");
		auto out = ostringstream();
		acwing654::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("0:9:16", ans);
	}

	TEST(acwing605, case1) {
		istringstream in("3\n"
		                 "9");
		auto out = ostringstream();
		acwing605::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("PROD = 27", ans);
	}

	TEST(acwing2041, case1) {
		istringstream in("7 4\n5 5\n2 4\n4 6\n3 5");
		auto out = ostringstream();
		acwing2041::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing2041, case2) {
		istringstream in("9 10\n"
		                 "5 5\n"
		                 "3 6\n"
		                 "6 6\n"
		                 "3 9\n"
		                 "1 7\n"
		                 "5 6\n"
		                 "6 8\n"
		                 "7 9\n"
		                 "4 6\n"
		                 "5 9");
		auto out = ostringstream();
		acwing2041::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing2041, case3) {
		istringstream in(
		        "23 100\n8 9\n2 14\n6 12\n13 18\n13 18\n5 17\n10 14\n1 13\n8 12\n17 19\n2 6\n4 19\n16 20\n4 15\n9 9\n13 19\n1 14\n4 17\n16 21\n7 15\n3 14\n7 19\n13 17\n3 8\n7 19\n6 8\n8 23\n5 19\n17 20\n10 20\n9 18\n20 23\n16 23\n7 7\n4 22\n4 23\n19 23\n10 18\n14 16\n2 7\n3 7\n4 18\n20 21\n13 17\n10 13\n5 17\n8 20\n21 22\n14 22\n4 21\n4 18\n4 10\n4 5\n19 20\n6 22\n3 15\n7 9\n3 22\n20 21\n3 12\n3 16\n8 18\n5 12\n9 23\n10 14\n5 10\n3 21\n18 22\n10 15\n2 17\n19 23\n9 12\n2 19\n3 15\n12 14\n3 3\n9 18\n9 22\n7 9\n1 21\n4 15\n2 6\n18 20\n3 17\n4 18\n8 15\n2 15\n9 19\n6 9\n5 21\n2 16\n1 20\n2 20\n13 20");
		auto out = ostringstream();
		acwing2041::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("46", ans);
	}

	namespace acwing2060 {
		TEST(acwing2060, case1) {
			istringstream in("6 16\n"
			                 "................\n"
			                 "..XXXX....XXX...\n"
			                 "...XXXX....XX...\n"
			                 ".XXXX......XXX..\n"
			                 "........XXXXX...\n"
			                 ".........XXX....");
			auto out = ostringstream();
			acwing2060::main(in, out);
			auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing2060

	namespace acwing2019 {
		TEST(acwing2019, case1) {
			istringstream in("7 6 3\n"
			                 "6 2\n"
			                 "5 2\n"
			                 "4 3\n"
			                 "2 1\n"
			                 "7 3\n"
			                 "5 4\n"
			                 "6 4");
			auto out = ostringstream();
			acwing2019::main(in, out);
			auto ans = out.str();
			ASSERT_EQ("1", ans);
		}

		TEST(acwing2019, case2) {
			istringstream in("4 2 2\n"
			                 "2 1\n"
			                 "1 2\n"
			                 "2 3\n"
			                 "4 2");
			auto out = ostringstream();
			acwing2019::main(in, out);
			auto ans = out.str();
			ASSERT_EQ("0", ans);
		}
	}// namespace acwing2019

	TEST(acwing611, case1) {
		istringstream in("12 1 5.30\n"
		                 "16 2 5.10");
		auto out = ostringstream();
		acwing611::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("VALOR A PAGAR: R$ 15.50", ans);
	}

	TEST(acwing612, case1) {
		istringstream in("3");
		auto out = ostringstream();
		acwing612::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("VOLUME = 113.097", ans);
	}

	TEST(acwing2014, case1) {
		istringstream in("8\n"
		                 "3\n"
		                 "5\n"
		                 "2\n"
		                 "3\n"
		                 "1\n"
		                 "4\n"
		                 "2\n"
		                 "3");
		auto out = ostringstream();
		acwing2014::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing2014, case2) {
		istringstream in("5\n"
		                 "3\n"
		                 "2\n"
		                 "2\n"
		                 "1\n"
		                 "3");
		auto out = ostringstream();
		acwing2014::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing607, case1) {
		istringstream in("5.0\n"
		                 "6.0\n"
		                 "7.0");
		auto out = ostringstream();
		acwing607::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("MEDIA = 6.3", ans);
	}

	TEST(acwing613, case1) {
		istringstream in("3.0 4.0 5.2");
		auto out = ostringstream();
		acwing613::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("TRIANGULO: 7.800\n"
		          "CIRCULO: 84.949\n"
		          "TRAPEZIO: 18.200\n"
		          "QUADRADO: 16.000\n"
		          "RETANGULO: 12.000",
		          ans);
	}

	TEST(acwing610, case1) {
		istringstream in("JOAO\n"
		                 "500.00\n"
		                 "1000.00");
		auto out = ostringstream();
		acwing610::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("TOTAL = R$ 650.00", ans);
	}

	TEST(acwing614, case1) {
		istringstream in("7 14 106");
		auto out = ostringstream();
		acwing614::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("106 eh o maior", ans);
	}

	TEST(acwing2005, case1) {
		istringstream in("4\n"
		                 "(())\n"
		                 "()((\n"
		                 "(()(\n"
		                 "))))");
		auto out = ostringstream();
		acwing2005::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("8", ans);
	}

	TEST(acwing2005, case2) {
		istringstream in("5\n"
		                 "(((()\n"
		                 "())((\n"
		                 "(((()\n"
		                 ")((((\n"
		                 ")))))");
		auto out = ostringstream();
		acwing2005::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("10", ans);
	}

	TEST(acwing617, case1) {
		istringstream in("30");
		auto out = ostringstream();
		acwing617::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("60 minutos", ans);
	}

	TEST(acwing618, case1) {
		istringstream in("10\n"
		                 "85");
		auto out = ostringstream();
		acwing618::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("70.833", ans);
	}

	TEST(acwing4206, case1) {
		istringstream in("40047");
		auto out = ostringstream();
		acwing4206::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("NO", ans);
	}

	TEST(acwing4206, case2) {
		istringstream in("7747774");
		auto out = ostringstream();
		acwing4206::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("YES", ans);
	}

	TEST(acwing4207, case1) {
		istringstream in("(()))(");
		auto out = ostringstream();
		acwing4207::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing4207, case2) {
		istringstream in("()()(()(((");
		auto out = ostringstream();
		acwing4207::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing1996, case1) {
		istringstream in("4\n"
		                 "essieb\n"
		                 "a\n"
		                 "xzy\n"
		                 "elsie");
		auto out = ostringstream();
		acwing1996::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("2 3\n"
		          "1 1\n"
		          "4 4\n"
		          "2 3\n",
		          ans);
	}

	TEST(acwing656, case1) {
		istringstream in("576.73");
		auto out = ostringstream();
		acwing656::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("NOTAS:\n"
		          "5 nota(s) de R$ 100.00\n"
		          "1 nota(s) de R$ 50.00\n"
		          "1 nota(s) de R$ 20.00\n"
		          "0 nota(s) de R$ 10.00\n"
		          "1 nota(s) de R$ 5.00\n"
		          "0 nota(s) de R$ 2.00\n"
		          "MOEDAS:\n"
		          "1 moeda(s) de R$ 1.00\n"
		          "1 moeda(s) de R$ 0.50\n"
		          "0 moeda(s) de R$ 0.25\n"
		          "2 moeda(s) de R$ 0.10\n"
		          "0 moeda(s) de R$ 0.05\n"
		          "3 moeda(s) de R$ 0.01",
		          ans);
	}

	TEST(acwing655, case1) {
		istringstream in("400");
		auto out = ostringstream();
		acwing655::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("1 ano(s)\n"
		          "1 mes(es)\n"
		          "5 dia(s)",
		          ans);
	}

	TEST(acwing665, case1) {
		istringstream in("6 24");
		auto out = ostringstream();
		acwing665::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("Sao Multiplos", ans);
	}

	TEST(acwing657, case1) {
		istringstream in("5 6 7 8");
		auto out = ostringstream();
		acwing657::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("Valores nao aceitos", ans);
	}

	TEST(acwing1987, case1) {
		istringstream in("6\n2 R\n6 L\n1 R\n8 L\n1 R\n2 R");
		auto out = ostringstream();
		acwing1987::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing660, case1) {
		istringstream in("3 2");
		auto out = ostringstream();
		acwing660::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("Total: R$ 10.00", ans);
	}

	TEST(acwing671, case1) {
		istringstream in("11");
		auto out = ostringstream();
		acwing671::main(in, out);
		auto ans = out.str();
		ASSERT_EQ("Sao Paulo", ans);
	}

	namespace acwing1978 {
		TEST(acwing1978, case1) {
			istringstream in("4\n"
			                 "-3 4\n"
			                 "7 8\n"
			                 "10 16\n"
			                 "3 9");
			auto out = ostringstream();
			acwing1978::main(in, out);
			auto ans = out.str();
			ASSERT_EQ("2", ans);
		}
	}// namespace acwing1978
}// namespace acwing
