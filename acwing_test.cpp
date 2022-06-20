#include "acwing.h"
#include "gtest/gtest.h"
#include <chrono>

namespace acwing {
	TEST(acwing1, case1) {
		istringstream in("3 4");
		auto out = ostringstream();
		acwing1::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing4200, case1) {
		istringstream in("2 7 1 8 2 8");
		auto out = ostringstream();
		acwing4200::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(acwing4200, case2) {
		istringstream in("20 30 40 50 0 100");
		auto out = ostringstream();
		acwing4200::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("20", ans);
	}

	TEST(acwing4200, case3) {
		istringstream in("31 41 59 26 17 43");
		auto out = ostringstream();
		acwing4200::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("9", ans);
	}

	TEST(acwing4201, case1) {
		istringstream in("10");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing4201, case2) {
		istringstream in("20");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing4201, case3) {
		istringstream in("100");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing4201, case4) {
		istringstream in("1000");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("8", ans);
	}

	TEST(acwing4201, case5) {
		istringstream in("10000");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("16", ans);
	}

	TEST(acwing4201, case6) {
		istringstream in("200");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing4201, case7) {
		istringstream in("101");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(acwing4201, case8) {
		istringstream in("1");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing4201, case9) {
		istringstream in("102");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(acwing4201, case10) {
		istringstream in("111");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing4201, case11) {
		istringstream in("110");
		auto out = ostringstream();
		acwing4201::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing608, case1) {
		istringstream in("5\n6\n7\n8");
		auto out = ostringstream();
		acwing608::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("DIFERENCA = -26", ans);
	}

	TEST(acwing604, case1) {
		istringstream in("2.00");
		auto out = ostringstream();
		acwing604::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("A=12.5664", ans);
	}

	TEST(acwing606, case1) {
		istringstream in("5.0\n7.1");
		auto out = ostringstream();
		acwing606::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("MEDIA = 6.43182", ans);
	}

	TEST(acwing609, case1) {
		istringstream in("25\n100\n5.50");
		auto out = ostringstream();
		acwing609::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("NUMBER = 25\n"
		          "SALARY = U$ 550.00",
		          ans);
	}

	TEST(acwing615, case1) {
		istringstream in("500\n35.0");
		auto out = ostringstream();
		acwing615::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("14.286 km/l", ans);
	}

	TEST(acwing616, case1) {
		istringstream in("1.0 7.0\n5.0 9.0");
		auto out = ostringstream();
		acwing616::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4.4721", ans);
	}

	TEST(acwing653, case1) {
		istringstream in("576");
		auto out = ostringstream();
		acwing653::main(in, out);
		const auto ans = out.str();
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
		const auto ans = out.str();
		ASSERT_EQ("NO", ans);
	}

	TEST(acwing4203, case2) {
		istringstream in("1000000001");
		auto out = ostringstream();
		acwing4203::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("YES", ans);
	}

	TEST(acwing4204, case1) {
		istringstream in("2");
		auto out = ostringstream();
		acwing4204::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0 1\n"
		          "1 0",
		          ans);
	}

	TEST(acwing4204, case2) {
		istringstream in("4");
		auto out = ostringstream();
		acwing4204::main(in, out);
		const auto ans = out.str();
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
		const auto ans = out.str();
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
		const auto ans = out.str();
		ASSERT_EQ("14", ans);
	}

	TEST(acwing654, case1) {
		istringstream in("556");
		auto out = ostringstream();
		acwing654::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0:9:16", ans);
	}

	TEST(acwing605, case1) {
		istringstream in("3\n"
		                 "9");
		auto out = ostringstream();
		acwing605::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("PROD = 27", ans);
	}

	TEST(acwing2041, case1) {
		istringstream in("7 4\n5 5\n2 4\n4 6\n3 5");
		auto out = ostringstream();
		acwing2041::main(in, out);
		const auto ans = out.str();
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
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing2041, case3) {
		istringstream in(
		        "23 100\n8 9\n2 14\n6 12\n13 18\n13 18\n5 17\n10 14\n1 13\n8 12\n17 19\n2 6\n4 19\n16 20\n4 15\n9 9\n13 19\n1 14\n4 17\n16 21\n7 15\n3 14\n7 19\n13 17\n3 8\n7 19\n6 8\n8 23\n5 19\n17 20\n10 20\n9 18\n20 23\n16 23\n7 7\n4 22\n4 23\n19 23\n10 18\n14 16\n2 7\n3 7\n4 18\n20 21\n13 17\n10 13\n5 17\n8 20\n21 22\n14 22\n4 21\n4 18\n4 10\n4 5\n19 20\n6 22\n3 15\n7 9\n3 22\n20 21\n3 12\n3 16\n8 18\n5 12\n9 23\n10 14\n5 10\n3 21\n18 22\n10 15\n2 17\n19 23\n9 12\n2 19\n3 15\n12 14\n3 3\n9 18\n9 22\n7 9\n1 21\n4 15\n2 6\n18 20\n3 17\n4 18\n8 15\n2 15\n9 19\n6 9\n5 21\n2 16\n1 20\n2 20\n13 20");
		auto out = ostringstream();
		acwing2041::main(in, out);
		const auto ans = out.str();
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
			const auto ans = out.str();
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
			const auto ans = out.str();
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
			const auto ans = out.str();
			ASSERT_EQ("0", ans);
		}
	}// namespace acwing2019

	TEST(acwing611, case1) {
		istringstream in("12 1 5.30\n"
		                 "16 2 5.10");
		auto out = ostringstream();
		acwing611::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("VALOR A PAGAR: R$ 15.50", ans);
	}

	TEST(acwing612, case1) {
		istringstream in("3");
		auto out = ostringstream();
		acwing612::main(in, out);
		const auto ans = out.str();
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
		const auto ans = out.str();
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
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing607, case1) {
		istringstream in("5.0\n"
		                 "6.0\n"
		                 "7.0");
		auto out = ostringstream();
		acwing607::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("MEDIA = 6.3", ans);
	}

	TEST(acwing613, case1) {
		istringstream in("3.0 4.0 5.2");
		auto out = ostringstream();
		acwing613::main(in, out);
		const auto ans = out.str();
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
		const auto ans = out.str();
		ASSERT_EQ("TOTAL = R$ 650.00", ans);
	}

	TEST(acwing614, case1) {
		istringstream in("7 14 106");
		auto out = ostringstream();
		acwing614::main(in, out);
		const auto ans = out.str();
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
		const auto ans = out.str();
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
		const auto ans = out.str();
		ASSERT_EQ("10", ans);
	}

	TEST(acwing617, case1) {
		istringstream in("30");
		auto out = ostringstream();
		acwing617::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("60 minutos", ans);
	}

	TEST(acwing618, case1) {
		istringstream in("10\n"
		                 "85");
		auto out = ostringstream();
		acwing618::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("70.833", ans);
	}

	TEST(acwing4206, case1) {
		istringstream in("40047");
		auto out = ostringstream();
		acwing4206::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("NO", ans);
	}

	TEST(acwing4206, case2) {
		istringstream in("7747774");
		auto out = ostringstream();
		acwing4206::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("YES", ans);
	}

	TEST(acwing4207, case1) {
		istringstream in("(()))(");
		auto out = ostringstream();
		acwing4207::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing4207, case2) {
		istringstream in("()()(()(((");
		auto out = ostringstream();
		acwing4207::main(in, out);
		const auto ans = out.str();
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
		const auto ans = out.str();
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
		const auto ans = out.str();
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
		const auto ans = out.str();
		ASSERT_EQ("1 ano(s)\n"
		          "1 mes(es)\n"
		          "5 dia(s)",
		          ans);
	}

	TEST(acwing665, case1) {
		istringstream in("6 24");
		auto out = ostringstream();
		acwing665::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Sao Multiplos", ans);
	}

	TEST(acwing657, case1) {
		istringstream in("5 6 7 8");
		auto out = ostringstream();
		acwing657::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Valores nao aceitos", ans);
	}

	TEST(acwing1987, case1) {
		istringstream in("6\n2 R\n6 L\n1 R\n8 L\n1 R\n2 R");
		auto out = ostringstream();
		acwing1987::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing660, case1) {
		istringstream in("3 2");
		auto out = ostringstream();
		acwing660::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Total: R$ 10.00", ans);
	}

	TEST(acwing671, case1) {
		istringstream in("11");
		auto out = ostringstream();
		acwing671::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Sao Paulo", ans);
	}

	namespace acwing1978 {
		TEST(acwing1978, case1) {
			istringstream in("4\n-3 4\n7 8\n10 16\n3 9");
			auto out = ostringstream();
			acwing1978::main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2", ans);
		}
	}// namespace acwing1978

	TEST(acwing659, case1) {
		istringstream in("25.01");
		auto out = ostringstream();
		acwing659::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Intervalo (25,50]", ans);
	}

	TEST(acwing662, case1) {
		istringstream in("4.5 -2.2");
		auto out = ostringstream();
		acwing662::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Q4", ans);
	}

	TEST(acwing662, case2) {
		istringstream in("0.0 0.0");
		auto out = ostringstream();
		acwing662::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Origem", ans);
	}

	TEST(acwing1969, case1) {
		istringstream in("6 3\n7\n3\n4\n2\n3\n4");
		auto out = ostringstream();
		acwing1969::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing664, case1) {
		istringstream in("6.0 4.0 2.0");
		auto out = ostringstream();
		acwing664::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Area = 10.0", ans);
	}

	TEST(acwing664, case2) {
		istringstream in("6.0 4.0 2.1");
		auto out = ostringstream();
		acwing664::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Perimetro = 12.1", ans);
	}

	TEST(acwing666, case1) {
		istringstream in("7.0 5.0 7.0");
		auto out = ostringstream();
		acwing666::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("TRIANGULO ACUTANGULO\nTRIANGULO ISOSCELES\n", ans);
	}

	TEST(acwing666, case2) {
		istringstream in("1.6 9.3 9.9");
		auto out = ostringstream();
		acwing666::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("TRIANGULO OBTUSANGULO\n", ans);
	}

	TEST(acwing1960, case1) {
		auto sol = acwing1960();
		istringstream in("5 6\n1\n0\n0\n0\n0");
		auto out = ostringstream();
		sol.main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1\n1\n1\n0\n1\n", ans);
	}

	TEST(acwing1960, case2) {
		auto sol = acwing1960();
		istringstream in("11 731657697430757\n1\n1\n0\n0\n1\n0\n1\n1\n0\n1\n0");
		auto out = ostringstream();
		sol.main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1\n1\n0\n1\n0\n1\n0\n0\n0\n1\n1\n", ans);
	}

	TEST(acwing667, case1) {
		istringstream in("16 2");
		auto out = ostringstream();
		acwing667::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("O JOGO DUROU 10 HORA(S)", ans);
	}

	TEST(acwing667, case2) {
		istringstream in("0 0");
		auto out = ostringstream();
		acwing667::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("O JOGO DUROU 24 HORA(S)", ans);
	}

	TEST(acwing667, case3) {
		istringstream in("2 16");
		auto out = ostringstream();
		acwing667::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("O JOGO DUROU 14 HORA(S)", ans);
	}

	TEST(acwing668, case1) {
		istringstream in("7 8 9 10");
		auto out = ostringstream();
		acwing668::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("O JOGO DUROU 2 HORA(S) E 2 MINUTO(S)", ans);
	}

	TEST(acwing668, case2) {
		istringstream in("7 7 7 7");
		auto out = ostringstream();
		acwing668::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)", ans);
	}

	TEST(acwing668, case3) {
		istringstream in("7 10 8 9");
		auto out = ostringstream();
		acwing668::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("O JOGO DUROU 0 HORA(S) E 59 MINUTO(S)", ans);
	}

	TEST(acwing668, case4) {
		istringstream in("22 36 5 28");
		auto out = ostringstream();
		acwing668::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("O JOGO DUROU 6 HORA(S) E 52 MINUTO(S)", ans);
	}

	TEST(acwing1952, case1) {
		istringstream in("4 7 9 6\n"
		                 "5 8\n"
		                 "3 4\n"
		                 "13 20\n"
		                 "7 10");
		auto out = ostringstream();
		acwing1952::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("31", ans);
	}

	TEST(acwing1952, case2) {
		istringstream in("25 5 7 3\n3 6\n5 7\n3 5\n2 6\n1 9\n2 7\n0 9\n3 6\n0 6\n2 6\n1 8\n7 9\n0 2\n2 3\n5 7\n2 9\n2 8\n7 9\n3 6\n1 2\n3 9\n1 9\n4 7\n4 8\n0 5");
		auto out = ostringstream();
		acwing1952::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("159", ans);
	}

	TEST(acwing669, case1) {
		istringstream in("400.00");
		auto out = ostringstream();
		acwing669::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Novo salario: 460.00\n"
		          "Reajuste ganho: 60.00\n"
		          "Em percentual: 15 %",
		          ans);
	}

	TEST(acwing672, case1) {
		istringstream in("3002.00");
		auto out = ostringstream();
		acwing672::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("R$ 80.36", ans);
	}

	TEST(acwing672, case2) {
		istringstream in("1700.00");
		auto out = ostringstream();
		acwing672::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Isento", ans);
	}

	TEST(acwing1945, case1) {
		istringstream in("5\n"
		                 "3\n"
		                 "1\n"
		                 "10\n"
		                 "7\n"
		                 "4");
		auto out = ostringstream();
		acwing1945::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing4210, case1) {
		istringstream in("5");
		auto out = ostringstream();
		acwing4210::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7/3", ans);
	}

	TEST(acwing4210, case2) {
		istringstream in("3");
		auto out = ostringstream();
		acwing4210::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2/1", ans);
	}

	TEST(acwing4211, case1) {
		istringstream in("6\n4 8 6 3 12 9");
		auto out = ostringstream();
		acwing4211::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("9 3 6 12 4 8 ", ans);
	}

	TEST(acwing4211, case2) {
		istringstream in("4\n42 28 84 126");
		auto out = ostringstream();
		acwing4211::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("126 42 84 28 ", ans);
	}

	TEST(acwing4211, case3) {
		istringstream in("2\n1000000000000000000 3000000000000000000");
		auto out = ostringstream();
		acwing4211::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3000000000000000000 1000000000000000000 ", ans);
	}

	TEST(acwing4211, case4) {
		istringstream in("2\n1 3");
		auto out = ostringstream();
		acwing4211::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3 1 ", ans);
	}

	TEST(acwing4211, case5) {
		istringstream in("19\n46875000000000000 732421875000000 5859375000000000 11444091796875 2929687500000000 187500000000000000 91552734375000 11718750000000000 3000000000000000000 22888183593750 1464843750000000 375000000000000000 45776367187500 183105468750000 93750000000000000 366210937500000 23437500000000000 750000000000000000 1500000000000000000");
		auto out = ostringstream();
		acwing4211::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("11444091796875 22888183593750 45776367187500 91552734375000 183105468750000 366210937500000 732421875000000 1464843750000000 2929687500000000 5859375000000000 11718750000000000 23437500000000000 46875000000000000 93750000000000000 187500000000000000 375000000000000000 750000000000000000 1500000000000000000 3000000000000000000 ", ans);
	}

	TEST(acwing4211, case6) {
		istringstream in("3\n4 1 2");
		auto out = ostringstream();
		acwing4211::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 2 4 ", ans);
	}

	TEST(acwing670, case1) {
		istringstream in("vertebrado\n"
		                 "mamifero\n"
		                 "onivoro");
		auto out = ostringstream();
		acwing670::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("homem", ans);
	}

	TEST(acwing633, case1) {
		istringstream in("7 21 -14");
		auto out = ostringstream();
		acwing633::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-14\n"
		          "7\n"
		          "21\n"
		          "\n"
		          "7\n"
		          "21\n"
		          "-14\n",
		          ans);
	}

	TEST(acwing1934, case1) {
		istringstream in("2\n"
		                 "T 30\n"
		                 "D 10");
		auto out = ostringstream();
		acwing1934::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2970", ans);
	}

	TEST(acwing658, case1) {
		istringstream in("10.0 20.1 5.1");
		auto out = ostringstream();
		acwing658::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("R1 = -0.29788\nR2 = -1.71212", ans);
	}

	TEST(acwing658, case2) {
		istringstream in("0 -77.9 -113.4");
		auto out = ostringstream();
		acwing658::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Impossivel calcular", ans);
	}

	TEST(acwing661, case1) {
		istringstream in("2.0 4.0 7.5 8.0 6.4");
		auto out = ostringstream();
		acwing661::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Media: 5.4\nAluno em exame.\nNota do exame: 6.4\nAluno aprovado.\nMedia final: 5.9", ans);
	}

	TEST(acwing661, case2) {
		istringstream in("2.0 6.6 4.0 9.0");
		auto out = ostringstream();
		acwing661::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Media: 4.9\nAluno reprovado.", ans);
	}

	TEST(acwing661, case3) {
		istringstream in("9.0 4.0 8.5 9.0");
		auto out = ostringstream();
		acwing661::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Media: 7.3\nAluno aprovado.", ans);
	}

	namespace acwing1929 {
		TEST(acwing1929, case1) {
			istringstream in("3 3\n"
			                 "/ \\ \\ \n"
			                 "\\ \\ \\ \n"
			                 "/ \\ / \n");
			auto out = ostringstream();
			auto sol = Solution();
			sol.main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing1929

	TEST(acwing1922, case1) {
		istringstream in("4 3\n"
		                 "4 7\n"
		                 "10 15\n"
		                 "2 2\n"
		                 "5 1");
		auto out = ostringstream();
		acwing1922::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("11", ans);
	}

	TEST(acwing709, case1) {
		istringstream in("8");
		auto out = ostringstream();
		acwing709::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1\n"
		          "3\n"
		          "5\n"
		          "7\n",
		          ans);
	}

	TEST(acwing710, case1) {
		istringstream in("9");
		auto out = ostringstream();
		acwing710::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("9\n"
		          "11\n"
		          "13\n"
		          "15\n"
		          "17\n"
		          "19\n",
		          ans);
	}

	TEST(acwing1913, case1) {
		istringstream in("6\n"
		                 "4 G\n"
		                 "10 H\n"
		                 "7 G\n"
		                 "16 G\n"
		                 "1 G\n"
		                 "3 H");
		auto out = ostringstream();
		acwing1913::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing1913, case2) {
		istringstream in("100\n50342471 H\n793701969 H\n479380267 H\n322850570 H\n107220217 H\n702916784 H\n76105122 H\n977859145 H\n462580317 H\n752903482 G\n701677346 H\n745578932 G\n209942747 H\n366001634 G\n8895148 H\n363160307 H\n457268462 H\n844159672 H\n477135559 H\n487370706 H\n30405075 H\n41564405 H\n792279072 H\n133933823 H\n326111206 G\n839613841 H\n43151064 H\n368627305 H\n47356295 H\n464363815 H\n503776239 H\n950452123 H\n130832617 H\n876623576 G\n742326665 G\n268139368 H\n356667923 H\n284180703 G\n667525511 H\n38532381 H\n947453527 H\n413421673 H\n874641452 H\n677533224 H\n51853013 H\n298095972 H\n49952407 H\n227705083 H\n61944314 H\n57828701 H\n928673712 H\n993198658 H\n869295749 H\n654989109 H\n909540105 H\n182685631 H\n871003482 H\n495189220 H\n287340586 G\n245648322 H\n784143807 H\n98298213 H\n256795891 H\n265691040 H\n5864149 H\n813754596 H\n505001848 H\n735361925 G\n714238741 H\n182151278 H\n210462502 H\n784014380 H\n795921403 H\n821818049 H\n156476475 H\n589275076 H\n510524572 H\n915155957 H\n126081087 H\n328904991 G\n832381598 H\n235636871 H\n413682311 H\n924534587 H\n611903263 H\n730110657 G\n361152676 G\n980857199 H\n667364150 H\n518490516 H\n603008114 H\n824407236 H\n698447774 H\n283087973 H\n657933293 H\n801872211 H\n179492344 H\n608950412 H\n593296366 H\n958348686 H\n");
		auto out = ostringstream();
		acwing1913::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("345611436", ans);
	}

	TEST(acwing1913, case3) {
		istringstream in("2\n"
		                 "1 G\n"
		                 "3 H");
		auto out = ostringstream();
		acwing1913::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing712, case1) {
		istringstream in("7\n-5\n6\n-3.4\n4.6\n12");
		auto out = ostringstream();
		acwing712::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4 positive numbers", ans);
	}

	TEST(acwing711, case1) {
		istringstream in("140");
		auto out = ostringstream();
		acwing711::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 x 140 = 140\n2 x 140 = 280\n3 x 140 = 420\n4 x 140 = 560\n5 x 140 = 700\n6 x 140 = 840\n7 x 140 = 980\n8 x 140 = 1120\n9 x 140 = 1260\n10 x 140 = 1400\n", ans);
	}

	TEST(acwing1904, case1) {
		istringstream in("5\n0 1\n1 2\n2 3\n3 2\n6 1");
		auto out = ostringstream();
		acwing1904::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing714, case1) {
		istringstream in("6\n"
		                 "-5");
		auto out = ostringstream();
		acwing714::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(acwing714, case2) {
		istringstream in("15\n"
		                 "12");
		auto out = ostringstream();
		acwing714::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("13", ans);
	}

	TEST(acwing714, case3) {
		istringstream in("12\n"
		                 "12");
		auto out = ostringstream();
		acwing714::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(acwing718, case1) {
		istringstream in("10\n"
		                 "10 C\n"
		                 "6 R\n"
		                 "15 F\n"
		                 "5 C\n"
		                 "14 R\n"
		                 "9 C\n"
		                 "6 R\n"
		                 "8 F\n"
		                 "5 C\n"
		                 "14 R");
		auto out = ostringstream();
		acwing718::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Total: 92 animals\n"
		          "Total coneys: 29\n"
		          "Total rats: 40\n"
		          "Total frogs: 23\n"
		          "Percentage of coneys: 31.52 %\n"
		          "Percentage of rats: 43.48 %\n"
		          "Percentage of frogs: 25.00 %",
		          ans);
	}

	TEST(acwing1884, case1) {
		istringstream in("6\n"
		                 "COOWWW");
		auto out = ostringstream();
		acwing1884::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing4212, case1) {
		istringstream in("aaaa\naaaA");
		auto out = ostringstream();
		acwing4212::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(acwing4212, case2) {
		istringstream in("abs\nAbz");
		auto out = ostringstream();
		acwing4212::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-1", ans);
	}

	TEST(acwing4213, case1) {
		istringstream in("1 1 1 1\n+ + *");
		auto out = ostringstream();
		acwing4213::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing4213, case2) {
		istringstream in("2 2 2 2\n* * +");
		auto out = ostringstream();
		acwing4213::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("8", ans);
	}

	TEST(acwing4213, case3) {
		istringstream in("1 2 3 4\n* + +");
		auto out = ostringstream();
		acwing4213::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("9", ans);
	}

	TEST(acwing4214, case1) {
		istringstream in("5\n2 4 5 4 10\n40 30 20 10 40");
		auto out = ostringstream();
		acwing4214::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("90", ans);
	}

	TEST(acwing4214, case2) {
		istringstream in("3\n100 101 100\n2 4 5");
		auto out = ostringstream();
		acwing4214::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-1", ans);
	}

	TEST(acwing4214, case3) {
		istringstream in("10\n1 2 3 4 5 6 7 8 9 10\n10 13 11 14 15 12 13 13 18 13");
		auto out = ostringstream();
		acwing4214::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("33", ans);
	}

	TEST(acwing713, case1) {
		istringstream in("4\n14\n123\n10\n-25");
		auto out = ostringstream();
		acwing713::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2 in\n2 out", ans);
	}

	TEST(acwing721, case1) {
		istringstream in("5\n10\n3\n0");
		auto out = ostringstream();
		acwing721::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 2 3 4 5 \n1 2 3 4 5 6 7 8 9 10 \n1 2 3 \n", ans);
	}

	TEST(acwing719, case1) {
		istringstream in("7\n4 5\n13 10\n6 4\n3 3\n3 5\n3 4\n3 8");
		auto out = ostringstream();
		acwing719::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0\n11\n5\n0\n0\n0\n12\n", ans);
	}

	TEST(acwing1875, case1) {
		istringstream in("10\nB 2\nE 5\nS 7\nI 10\nO 16\nM 19\nB 3\nG 1\nI 9\nM 2");
		auto out = ostringstream();
		acwing1875::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing720, case1) {
		istringstream in("3 2");
		auto out = ostringstream();
		acwing720::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing720, case2) {
		istringstream in("3 -1 0 -2 2");
		auto out = ostringstream();
		acwing720::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing717, case1) {
		istringstream in("5");
		auto out = ostringstream();
		acwing717::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0 1 1 2 3 ", ans);
	}

	TEST(acwing1855, case1) {
		istringstream in("6\n"
		                 "8\n"
		                 "5\n"
		                 "6\n"
		                 "13\n"
		                 "3\n"
		                 "4");
		auto out = ostringstream();
		acwing1855::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(acwing1855, case2) {
		istringstream in("10\n"
		                 "2\n"
		                 "3\n"
		                 "11\n"
		                 "10\n"
		                 "8\n"
		                 "5\n"
		                 "0\n"
		                 "12\n"
		                 "4\n"
		                 "6");
		auto out = ostringstream();
		acwing1855::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("10", ans);
	}

	TEST(acwing724, case1) {
		istringstream in("6");
		auto out = ostringstream();
		acwing724::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1\n"
		          "2\n"
		          "3\n"
		          "6",
		          ans);
	}

	TEST(acwing722, case1) {
		istringstream in("2 5\n"
		                 "6 3\n"
		                 "5 0");
		auto out = ostringstream();
		acwing722::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2 3 4 5 Sum=14\n"
		          "3 4 5 6 Sum=18\n",
		          ans);
	}

	TEST(acwing1843, case1) {
		istringstream in("5\n"
		                 "4\n"
		                 "7\n"
		                 "8\n"
		                 "6\n"
		                 "4");
		auto out = ostringstream();
		acwing1843::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("48", ans);
	}

	TEST(acwing723, case1) {
		istringstream in("7 4");
		auto out = ostringstream();
		acwing723::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 2 3 PUM\n"
		          "5 6 7 PUM\n"
		          "9 10 11 PUM\n"
		          "13 14 15 PUM\n"
		          "17 18 19 PUM\n"
		          "21 22 23 PUM\n"
		          "25 26 27 PUM\n",
		          ans);
	}

	TEST(acwing725, case1) {
		istringstream in("3\n"
		                 "6\n"
		                 "5\n"
		                 "28");
		auto out = ostringstream();
		acwing725::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6 is perfect\n"
		          "5 is not perfect\n"
		          "28 is perfect\n",
		          ans);
	}

	TEST(acwing725, case2) {
		istringstream in("1\n"
		                 "28");
		auto out = ostringstream();
		acwing725::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("28 is perfect\n",
		          ans);
	}

	namespace acwing1826 {
		TEST(acwing1826, case1) {
			istringstream in("4\n"
			                 "2 4\n"
			                 "1 1\n"
			                 "5 2\n"
			                 "17 25");
			auto out = ostringstream();
			acwing1826::main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("12", ans);
		}
	}// namespace acwing1826

	TEST(acwing1813, case1) {
		istringstream in("3\n"
		                 "fox box\n"
		                 "dog cat\n"
		                 "car bus");
		auto out = ostringstream();
		acwing1813::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2\n2\n2\n1\n0\n1\n1\n0\n0\n0\n0\n0\n0\n0\n2\n0\n0\n1\n1\n1\n1\n0\n0\n1\n0\n0\n", ans);
	}

	TEST(acwing726, case1) {
		istringstream in("3\n"
		                 "8\n"
		                 "51\n"
		                 "7");
		auto out = ostringstream();
		acwing726::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("8 is not prime\n"
		          "51 is not prime\n"
		          "7 is prime\n",
		          ans);
	}

	TEST(acwing737, case1) {
		istringstream in("10\n-9\n0\n-4\n-10\n0\n-2\n-7\n7\n4");
		auto out = ostringstream();
		acwing737::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("X[0] = 10\nX[1] = 1\nX[2] = 1\nX[3] = 1\nX[4] = 1\nX[5] = 1\nX[6] = 1\nX[7] = 1\nX[8] = 7\nX[9] = 4\n", ans);
	}

	TEST(acwing1801, case1) {
		istringstream in("5\n1 2\n2 2\n1 3\n1 1\n3 2");
		auto out = ostringstream();
		acwing1801::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing4215, case1) {
		istringstream in("tour");
		auto out = ostringstream();
		acwing4215::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ(".t.r", ans);
	}

	TEST(acwing4215, case2) {
		istringstream in("aBAcAba");
		auto out = ostringstream();
		acwing4215::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ(".b.c.b", ans);
	}

	TEST(acwing4216, case1) {
		istringstream in("6 6\n6 3\n6 4\n5 1\n2 5\n1 4\n5 4");
		auto out = ostringstream();
		acwing4216::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("YES", ans);
	}

	TEST(acwing4216, case2) {
		istringstream in("6 5\n5 6\n4 6\n3 1\n5 1\n1 2");
		auto out = ostringstream();
		acwing4216::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("NO", ans);
	}

	TEST(acwing4217, case1) {
		istringstream in("5\nRURUU\n-2 3");
		auto out = ostringstream();
		auto sol = acwing4217();
		sol.main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing4217, case2) {
		istringstream in("4\nRULR\n1 1");
		auto out = ostringstream();
		auto sol = acwing4217();
		sol.main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(acwing4217, case3) {
		istringstream in("3\nUUU\n100 100");
		auto out = ostringstream();
		auto sol = acwing4217();
		sol.main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-1", ans);
	}

	TEST(acwing4217, case4) {
		istringstream in("100\nURDLDDLLDDLDDDRRLLRRRLULLRRLUDUUDUULURRRDRRLLDRLLUUDLDRDLDDLDLLLULRURRUUDDLDRULRDRUDDDDDDULRDDRLRDDL\n-59 -1");
		auto out = ostringstream();
		auto sol = acwing4217();
		sol.main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("58", ans);
	}

	TEST(acwing738, case1) {
		istringstream in("1");
		auto out = ostringstream();
		acwing738::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("N[0] = 1\nN[1] = 2\nN[2] = 4\nN[3] = 8\nN[4] = 16\nN[5] = 32\nN[6] = 64\nN[7] = 128\nN[8] = 256\nN[9] = 512\n", ans);
	}

	TEST(acwing741, case1) {
		istringstream in("3\n0\n4\n2");
		auto out = ostringstream();
		acwing741::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Fib(0) = 0\nFib(4) = 3\nFib(2) = 1\n", ans);
	}

	TEST(acwing1789, case1) {
		istringstream in("ABCCABDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZ");
		auto out = ostringstream();
		acwing1789::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing742, case1) {
		istringstream in("10\n"
		                 "1 2 3 4 -5 6 7 8 9 10");
		auto out = ostringstream();
		acwing742::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Minimum value: -5\n"
		          "Position: 4",
		          ans);
	}

	TEST(acwing1776, case1) {
		istringstream in("3 8\n"
		                 "AATCCCAT\n"
		                 "GATTGCAA\n"
		                 "GGTCGCAA\n"
		                 "ACTCCCAG\n"
		                 "ACTCGCAT\n"
		                 "ACTTCCAT");
		auto out = ostringstream();
		acwing1776::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing743, case1) {
		istringstream in("7\n"
		                 "S\n"
		                 "8.3 -9.4 -5.6 9.9 2.2 3.2 6.9 7.7 -2.9 -6.3 3.9 -1.4\n"
		                 "-0.5 4.3 -0.3 2.3 0.7 -3.1 -6.3 5.7 -7.7 -3.7 9.7 3.8\n"
		                 "5.8 -9.1 3.5 7.0 2.5 -2.3 6.9 2.7 5.8 -4.6 -7.8 4.3\n"
		                 "-1.7 -8.9 -2.6 7.5 -9.6 6.4 -4.7 -8.0 0.6 6.7 -1.8 -0.4\n"
		                 "-9.8 8.9 -3.8 -2.1 5.8 -9.4 1.3 6.3 -1.3 -6.3 -6.6 8.8\n"
		                 "-6.3 -7.2 -6.3 -5.9 6.2 9.3 2.0 -4.3 2.7 3.6 -4.6 8.7\n"
		                 "3.8 7.4 8.7 -2.8 6.0 -9.2 1.9 3.1 -7.2 -6.0 9.7 -8.4\n"
		                 "-9.8 6.6 8.6 2.3 1.1 -2.9 6.6 -1.5 2.1 -5.1 6.4 -7.5\n"
		                 "-0.6 -1.6 9.5 -6.6 3.0 3.4 -7.5 -7.9 3.1 2.0 1.7 -7.6\n"
		                 "-9.0 9.4 6.6 -0.2 1.4 6.5 8.6 2.0 -1.3 0.2 4.0 -2.4\n"
		                 "-7.3 -6.3 -8.6 -7.5 8.5 1.4 -3.3 7.1 0.8 3.3 3.0 0.1\n"
		                 "3.3 9.0 1.7 5.2 -3.7 8.9 3.8 -7.4 -2.8 0.6 -2.4 7.1");
		auto out = ostringstream();
		acwing743::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6.9", ans);
	}

	TEST(acwing1762, case1) {
		istringstream in("5\n1 3 4 5 2\n1234567 2222222 3333333 4444444 5555555");
		auto out = ostringstream();
		acwing1762::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1234567\n5555555\n2222222\n3333333\n4444444\n", ans);
	}

	TEST(acwing1750, case1) {
		istringstream in("3\n5 9\n1 4\n3 7");
		auto out = ostringstream();
		auto sol = acwing1750();
		acwing1750::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("7", ans);
	}

	TEST(acwing1738, case1) {
		istringstream in("5\n"
		                 "7 1 3 11 4");
		auto out = ostringstream();
		acwing1738::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing1738, case2) {
		istringstream in("10\n"
		                 "384 887 778 916 794 336 387 493 650 422");
		auto out = ostringstream();
		acwing1738::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing4297, case1) {
		istringstream in("5\n1 3 1 1 4");
		auto out = ostringstream();
		acwing4297::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5", ans);
	}

	TEST(acwing4297, case2) {
		istringstream in("5\n1 3 2 1 4");
		auto out = ostringstream();
		acwing4297::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing4297, case3) {
		istringstream in("3\n4 1 2");
		auto out = ostringstream();
		acwing4297::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(acwing4297, case4) {
		istringstream in("1\n2");
		auto out = ostringstream();
		acwing4297::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(acwing4298, case1) {
		istringstream in("4\n1 4 6 2\n5\n5 1 5 7 9");
		auto out = ostringstream();
		auto sol = acwing4298();
		sol.main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing4298, case2) {
		istringstream in("4\n1 2 3 4\n4\n10 11 12 13");
		auto out = ostringstream();
		auto sol = acwing4298();
		sol.main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0", ans);
	}

	TEST(acwing4298, case3) {
		istringstream in("5\n1 1 1 1 1\n3\n1 2 3");
		auto out = ostringstream();
		auto sol = acwing4298();
		sol.main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing1726, case1) {
		istringstream in("6 3 2\n"
		                 "4 5 6\n"
		                 "5 3\n"
		                 "3 1");
		auto out = ostringstream();
		acwing1726::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing753, case1) {
		istringstream in("1\n"
		                 "2\n"
		                 "3\n"
		                 "4\n"
		                 "5\n"
		                 "0");
		auto out = ostringstream();
		acwing753::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 \n"
		          "\n"
		          "1 1 \n"
		          "1 1 \n"
		          "\n"
		          "1 1 1 \n"
		          "1 2 1 \n"
		          "1 1 1 \n"
		          "\n"
		          "1 1 1 1 \n"
		          "1 2 2 1 \n"
		          "1 2 2 1 \n"
		          "1 1 1 1 \n"
		          "\n"
		          "1 1 1 1 1 \n"
		          "1 2 2 2 1 \n"
		          "1 2 3 2 1 \n"
		          "1 2 2 2 1 \n"
		          "1 1 1 1 1 \n"
		          "\n",
		          ans);
	}

	TEST(acwing1715, case1) {
		istringstream in("3\n"
		                 "4 10 1\n"
		                 "8 13 3\n"
		                 "2 6 2");
		auto out = ostringstream();
		acwing1715::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing756, case1) {
		istringstream in("3 3");
		auto out = ostringstream();
		acwing756::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 2 3 \n"
		          "8 9 4 \n"
		          "7 6 5 \n",
		          ans);
	}

	TEST(acwing1696, case1) {
		istringstream in("4\n"
		                 "1 2 4 3");
		auto out = ostringstream();
		acwing1696::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing760, case1) {
		istringstream in("I love Beijing.");
		auto out = ostringstream();
		acwing760::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("15", ans);
	}

	TEST(acwing762, case1) {
		istringstream in("0.4\n"
		                 "abcde\n"
		                 "xbacd");
		auto out = ostringstream();
		acwing762::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("no", ans);
	}

	TEST(acwing1684, case1) {
		istringstream in("5 6\n"
		                 "4 1\n"
		                 "4 2\n"
		                 "4 3\n"
		                 "2 5\n"
		                 "1 2\n"
		                 "1 5");
		auto out = ostringstream();
		acwing1684::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("12133", ans);
	}

	TEST(acwing761, case1) {
		istringstream in("I am 18 years old this year.");
		auto out = ostringstream();
		acwing761::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing768, case1) {
		istringstream in("Hello\nhello");
		auto out = ostringstream();
		acwing768::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("=", ans);
	}

	TEST(acwing1471, case1) {
		istringstream in("3\n1 2\n3 2");
		auto out = ostringstream();
		acwing1471::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing763, case1) {
		istringstream in("3\n"
		                 "Hunter Gun\n"
		                 "Bear Bear\n"
		                 "Hunter Bear");
		auto out = ostringstream();
		acwing763::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Player1\n"
		          "Tie\n"
		          "Player2\n",
		          ans);
	}

	TEST(acwing766, case1) {
		istringstream in("Hello      world.This is    c language.");
		auto out = ostringstream();
		acwing766::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Hello world.This is c language.", ans);
	}

	TEST(acwing1460, case1) {
		istringstream in("7\n"
		                 "ABCDABC");
		auto out = ostringstream();
		acwing1460::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing4299, case1) {
		istringstream in("3\n1 1\n-1 -1\n2 -1");
		auto out = ostringstream();
		acwing4299::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Yes", ans);
	}

	TEST(acwing4299, case2) {
		istringstream in("4\n1 1\n2 2\n-1 1\n-2 2");
		auto out = ostringstream();
		acwing4299::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("No", ans);
	}

	TEST(acwing4299, case3) {
		istringstream in("3\n1 2\n2 1\n4 60");
		auto out = ostringstream();
		acwing4299::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Yes", ans);
	}

	TEST(acwing4300, case1) {
		istringstream in("4 6");
		auto out = ostringstream();
		acwing4300::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing4300, case2) {
		istringstream in("10 1");
		auto out = ostringstream();
		acwing4300::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("9", ans);
	}

	TEST(acwing4301, case1) {
		istringstream in("5\n73452");
		auto out = ostringstream();
		acwing4301::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("YES", ans);
	}

	TEST(acwing4301, case2) {
		istringstream in("4\n1248");
		auto out = ostringstream();
		acwing4301::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("NO", ans);
	}

	TEST(acwing765, case1) {
		istringstream in("test case");
		auto out = ostringstream();
		acwing765::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("t e s t   c a s e ", ans);
	}

	TEST(acwing767, case1) {
		istringstream in("Hello! How are you!");
		auto out = ostringstream();
		acwing767::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("Ifmmp! Ipx bsf zpv!", ans);
	}

	TEST(acwing769, case1) {
		istringstream in("hello\n"
		                 "l");
		auto out = ostringstream();
		acwing769::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("he##o", ans);
	}

	TEST(acwing764, case1) {
		istringstream in("1 2 3");
		auto out = ostringstream();
		acwing764::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("QRRSd", ans);
	}

	TEST(acwing1443, case1) {
		istringstream in("5\n"
		                 "4 6 7 6");
		auto out = ostringstream();
		acwing1443::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3 1 5 2 4 ", ans);
	}

	TEST(acwing773, case1) {
		istringstream in("abcab eee\n"
		                 "12343 555");
		auto out = ostringstream();
		acwing773::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("abceeeab\n"
		          "12345553\n",
		          ans);
	}

	TEST(acwing770, case1) {
		istringstream in("You want someone to help you\n"
		                 "You\n"
		                 "I");
		auto out = ostringstream();
		acwing770::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("I want someone to help you ", ans);
	}

	TEST(acwing1672, case1) {
		istringstream in("7\n"
		                 "GHHHGHH\n"
		                 "HHGGGHH");
		auto out = ostringstream();
		acwing1672::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing772, case1) {
		istringstream in("abceabcd");
		auto out = ostringstream();
		acwing772::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("e", ans);
	}

	TEST(acwing771, case1) {
		istringstream in("2\n"
		                 "aaaaabbbbbcccccccdddddddddd\n"
		                 "abcdefghigk");
		auto out = ostringstream();
		acwing771::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("d 10\n"
		          "a 1\n",
		          ans);
	}

	namespace acwing1660 {
		TEST(acwing1660, case1) {
			istringstream in("6\n"
			                 "7 1\n"
			                 "1 1\n"
			                 "15 1\n"
			                 "3 1\n"
			                 "10 0\n"
			                 "6 1");
			auto out = ostringstream();
			acwing1660::main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing1660

	TEST(acwing774, case1) {
		istringstream in("I am a student of Peking University.");
		auto out = ostringstream();
		acwing774::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("University", ans);
	}

	TEST(acwing775, case1) {
		istringstream in("I am a student");
		auto out = ostringstream();
		acwing775::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("student a am I ", ans);
	}

	TEST(acwing3347, case1) {
		istringstream in("4\n"
		                 "1 1 2 3");
		auto out = ostringstream();
		acwing3347::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing777, case1) {
		istringstream in("abcd\n"
		                 "aaaa\n"
		                 "ababab\n"
		                 ".");
		auto out = ostringstream();
		acwing777::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1\n"
		          "4\n"
		          "3\n",
		          ans);
	}

	TEST(acwing776, case1) {
		istringstream in("AABCD CDAA");
		auto out = ostringstream();
		acwing776::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("true", ans);
	}

	TEST(acwing4302, case1) {
		istringstream in("3\n1 -2 0");
		auto out = ostringstream();
		acwing4302::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing4302, case2) {
		istringstream in("6\n16 23 16 15 42 8");
		auto out = ostringstream();
		acwing4302::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("120", ans);
	}

	TEST(acwing4304, case1) {
		istringstream in("4\na\nb\nab\nd");
		auto out = ostringstream();
		acwing4304::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing4304, case2) {
		istringstream in("3\nab\nbc\nabc");
		auto out = ostringstream();
		acwing4304::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing4304, case3) {
		istringstream in("1\nabcdefghijklmn");
		auto out = ostringstream();
		acwing4304::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing778, case1) {
		istringstream in("abcd123ab888efghij45ef67kl,ab,ef");
		auto out = ostringstream();
		acwing778::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("18", ans);
	}

	TEST(acwing778, case2) {
		istringstream in("abcde,abc,bcd");
		auto out = ostringstream();
		acwing778::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-1", ans);
	}

	TEST(acwing778, case3) {
		istringstream in("CdqpUQX2G3Ek0vWfdIPopo0ZiHBaDeWnJWXUFBkHVrKGcld7g85DoKGvixBMYmV6GT4ndhdN2W3EknSm5LqEgN26GF96eB8s73Ek,Sm5LqEg,3Ek");
		auto out = ostringstream();
		acwing778::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("12", ans);
	}

	TEST(acwing778, case4) {
		istringstream in("KOqRYKCcGkTnagtoeR14B2GSO3CStZUslISdqepllSeAfjVfVHqF8sRzaeV3r2LeQnQpu9MbYY1090oHlfobNzk5vTkLaV6qEDmMLlPUFlZuXnvB04UXTRUrLozeT5RYPZl43EdOwr7wYhFh3VJsDhn0B5D1IGkwzeADgPlJROu7MmRj0vqCBlWBnSZj5L6G7jRF6pTkZaswE7emZRRLXMRmSNxbHFlSfipL6biuSk6Lw0UeYGFuKZs8QDLzBrBYwNqbZyAlki45tufXWLift7Z9IqKfcVYspARBIMAv0OX8,LozeT5RYP,lP,Sm5LqEg,3Ek");
		auto out = ostringstream();
		acwing778::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("-1", ans);
	}

	TEST(acwing779, case1) {
		istringstream in("3\nbaba\naba\ncba\n2\naa\ncc\n2\naa\na\n0");
		auto out = ostringstream();
		acwing779::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("ba\n\na\n", ans);
	}

	TEST(acwing779, case2) {
		istringstream in("30\nnEoEScu\nZaeeACDJMPeugIe\npKTHmh\nkgSkIDuCqsEVpfWRgCkqFJLCJlqa\nOpd\nclMNzGWsFmLUdEjcIArnKnoZefM\ndNQtHCvZBvYuvxvBpZcuzYTKHjoqfi\njaKFnCmLSKv\ntwcakyTMLKdcJchpAf\nA\nnmafrdXuv\nLDJqRlEPZIXYeXXmHGXIaIkyLGxQ\nNGcGolaHClIEIPHsCDXaLOnmTUN\nqTQsxRcoZCmtZEIWSRYhur\nrykHNbbz\nseUPknypePTBHWSpMEXVyvquGTBtl\nlIRLLXRSYoSqCYeDcm\nb\nOAaRrcHFeoiRMkPraTBvqnVuqLsdY\nYyE\nMuyRhuWDdKqUdye\nlCvXQCbksXpkiKjiNK\nquItljpXxNZJs\nuYyzRLGDMUxzF\nDtYH\nUtCNQdnVhyCCUXBNFKgAvopmUH\nJvFbR\nDYrs\nxyHO\nv\n30\nrVygjuehTDCpUAXsbfphOmGYFL\nQPICAWIMDYFL\nsoDChYFL\nYIekoOFOZNjEEMYFL\nhNkyveMOoCmTZjPBIXiAnxDyfaYFL\nAVyriYTqOzYifQHfFumCFIAYFL\nDJYFL\nZJCDXYFL\nmzpfPMZeDwFoCCdCCpBpNcCYFL\nyIfnWzqfnnLmKesrJdtZZhBvOYYYFL\nsTArOZYFL\nmviuiCGDWxSjvrmRJzLIjNZeWFYFL\nrMCDDIYFL\nECrYFL\nqMZnaycgcDSYFL\nyysGWCYFL\nLawdLVBtSGYzBPVHyEBYFL\njYFL\nLAshGRGiKGuWONTRlKIYFL\nOaOwBeLgJTuXwIGRxMJYmowYFL\noaqOXEQeXEHXSovxQPoBkuTOGOYFL\nPlheYFL\nzpjaulbZXnTPQNckLlgvGIwiiswYFL\nRRUcMWVqlodYFL\nBXyJZXBKMOYFL\nbZivyYFL\nbUzMJcPNNDZhxaJeUmYFL\nnqNNoChHurWqWvQYFL\nLYFL\nzuoFKmVhTgyJljmuZcvkuomYFL\n30\nxEVZD\nfRVZD\ndmQEISVZD\nxHXbvTDrfORRzSHzGpAvybwMLVZD\nvUWDBiunOnyOchFlofVZD\nTDfoUHwJozMFChjjHKJVZD\ncHHYVZD\ncUBbkwaNAeTVZD\nFIuKsscZVvFtQktHkRBrHXVZD\nxLtWSUDVZD\nNIuxqauDaGCtcTkRxCgYAVZD\nkccsRWBfjvaaQJJoSnSrojerpPVZD\ndGIqkKGVZD\nZdFFnBVZD\nWxpyqMqVzeUiVZD\ntRcJlVZD\nYeCcIAHpNNDmvcwfQKVOWHcVZD\nQpNjpVXDrnAdYfVZD\nTKPBPkXcKPxzqyWZyUMlidOrxeVZD\nTVZD\nqFmmojqFRgxHQlEPWJaVZD\nyYwSyfXCJMYImSPaWbrOICSVZD\nJsVZD\notxyOTdyWVZD\nhlGzZrNatBVZD\npaKqVStOuxVZD\nsWQcmVZD\nJQCOynpNzexVZD\nMPzHWsTJEWgZZLoGSDCVZD\nLVZD\n30\nbWXjqUDxQtqWrTs\nhLOaWKvGApgoZfEIgyMvLCKTs\nstdgCWunkATs\nlaaKwHVnTs\nTTs\nOVVEcqRoGEinsIEoszUTs\nLTwzYpsPJVQTyHCKIqmCLNdkTs\nxjZOBXSTs\nljPbiauxwdayAdARChbTs\nPwpUxAnHCZXhSJwTs\nmxiCOoiiTs\nxtemzqhoYUVSHVbIPmTs\newvKtcpjralBkxnPPtTs\nMKzjTs\nJmLzHqNBbCslRqwBXWnygYwPOTTs\nqqWtjigdASztibHjzdedNsqTs\nBlXPWKiTs\nEisQTs\nvnOMHcFuxqCEsGTs\nIlnIBHZxHdqAiaTs\nzpegvMdYpFnSIoFTs\nEPIHFxOaUBBbrfEodOITs\nGOAimQOTs\nMlTs\ntoRynPMxSklAfxzTs\neLTs\nauEDlTlGFEkBTs\nQkKwiXugeRdWPGMPTs\ngaTs\nprtfvmLKTGjbPSTs\n0");
		auto out = ostringstream();
		acwing779::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("\nYFL\nVZD\nTs\n", ans);
	}

	TEST(acwing804, case1) {
		istringstream in("3");
		auto out = ostringstream();
		acwing804::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing810, case1) {
		istringstream in("-3");
		auto out = ostringstream();
		acwing810::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing805, case1) {
		istringstream in("3 6");
		auto out = ostringstream();
		acwing805::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing806, case1) {
		istringstream in("1.11 2.22");
		auto out = ostringstream();
		acwing806::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3.33", ans);
	}

	TEST(acwing808, case1) {
		istringstream in("12 16");
		auto out = ostringstream();
		acwing808::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing807, case1) {
		istringstream in("3 5");
		auto out = ostringstream();
		acwing807::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("12", ans);
	}

	TEST(acwing811, case1) {
		istringstream in("3 5");
		auto out = ostringstream();
		acwing811::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("5 3", ans);
	}

	TEST(acwing809, case1) {
		istringstream in("6 8");
		auto out = ostringstream();
		acwing809::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("24", ans);
	}

	TEST(acwing812, case1) {
		istringstream in("5 3\n"
		                 "1 2 3 4 5");
		auto out = ostringstream();
		acwing812::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 2 3 ", ans);
	}

	TEST(acwing814, case1) {
		istringstream in("3 5 2\n"
		                 "1 2 3\n"
		                 "4 5 6 7 8");
		auto out = ostringstream();
		acwing814::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 2 6 7 8 ", ans);
	}

	TEST(acwing813, case1) {
		istringstream in("3 4\n"
		                 "1 3 4 5\n"
		                 "2 6 9 4\n"
		                 "1 4 7 5");
		auto out = ostringstream();
		acwing813::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 3 4 5 \n"
		          "2 6 9 4 \n"
		          "1 4 7 5 \n",
		          ans);
	}

	TEST(acwing815, case1) {
		istringstream in("I love AcWing.");
		auto out = ostringstream();
		acwing815::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("I love AcWing.", ans);
	}

	TEST(acwing4305, case1) {
		istringstream in("8");
		auto out = ostringstream();
		acwing4305::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("OOOoOooO", ans);
	}

	TEST(acwing4305, case2) {
		istringstream in("15");
		auto out = ostringstream();
		acwing4305::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("OOOoOooOooooOoo", ans);
	}

	TEST(acwing4306, case1) {
		istringstream in("4\n1 3 1 4");
		auto out = ostringstream();
		acwing4306::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	TEST(acwing4306, case2) {
		istringstream in("5\n1 2 3 2 5");
		auto out = ostringstream();
		acwing4306::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing4307, case1) {
		istringstream in("123\n222");
		auto out = ostringstream();
		acwing4307::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("213", ans);
	}

	TEST(acwing4307, case2) {
		istringstream in("3921\n10000");
		auto out = ostringstream();
		acwing4307::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("9321", ans);
	}

	TEST(acwing4307, case3) {
		istringstream in("4940\n5000");
		auto out = ostringstream();
		acwing4307::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4940", ans);
	}

	TEST(acwing4307, case4) {
		istringstream in("15778899\n98715689");
		auto out = ostringstream();
		acwing4307::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("98598771", ans);
	}

	TEST(acwing819, case1) {
		istringstream in("3");
		auto out = ostringstream();
		acwing819::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("6", ans);
	}

	TEST(acwing816, case1) {
		istringstream in("5 3\n1 2 3 4 5");
		auto out = ostringstream();
		acwing816::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3 2 1 4 5 ", ans);
	}

	TEST(acwing820, case1) {
		istringstream in("4");
		auto out = ostringstream();
		acwing820::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("3", ans);
	}

	TEST(acwing817, case1) {
		istringstream in("5\n"
		                 "1 1 2 4 5");
		auto out = ostringstream();
		acwing817::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4", ans);
	}

	TEST(acwing818, case1) {
		istringstream in("5 2 4\n"
		                 "4 5 1 3 2");
		auto out = ostringstream();
		acwing818::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4 5 1 2 3 ", ans);
	}

	TEST(acwing821, case1) {
		istringstream in("5");
		auto out = ostringstream();
		acwing821::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("8", ans);
	}

	TEST(acwing822, case1) {
		istringstream in("2 3");
		auto out = ostringstream();
		acwing822::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("10", ans);
	}

	TEST(acwing823, case1) {
		istringstream in("3");
		auto out = ostringstream();
		acwing823::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 2 3 \n"
		          "1 3 2 \n"
		          "2 1 3 \n"
		          "2 3 1 \n"
		          "3 1 2 \n"
		          "3 2 1 \n",
		          ans);
	}

	namespace acwing21 {
		TEST(acwing21, case1) {
			ASSERT_EQ(5, Solution::Fibonacci(5));
		}
	}// namespace acwing21

	namespace acwing78 {
		TEST(acwing78, case1) {
			ASSERT_EQ("cdefgab", Solution::leftRotateString("abcdefg", 2));
		}
	}// namespace acwing78

	namespace acwing16 {
		TEST(acwing16, case1) {
			string input = "We are happy.";
			ASSERT_EQ("We%20are%20happy.", Solution::replaceSpaces(input));
		}
	}// namespace acwing16

	namespace acwing87 {
		TEST(acwing87, case1) {
			ASSERT_EQ(123, Solution::strToInt("123"));
		}
	}// namespace acwing87

	TEST(acwing4308, case1) {
		istringstream in("happy birthday");
		auto out = ostringstream();
		acwing4308::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("hab", ans);
	}

	TEST(acwing4308, case2) {
		istringstream in("abc defg");
		auto out = ostringstream();
		acwing4308::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("abcd", ans);
	}

	TEST(acwing4309, case1) {
		istringstream in("4 0 0\n1 1\n2 2\n2 0\n-1 -1");
		auto out = ostringstream();
		acwing4309::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2", ans);
	}

	TEST(acwing4309, case2) {
		istringstream in("2 1 2\n1 1\n1 0");
		auto out = ostringstream();
		acwing4309::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1", ans);
	}

	namespace acwing4310 {
		TEST(acwing4310, case1) {
			istringstream in("9 6\n1 1 1 3 5 3 5 7\n3 1\n1 5\n3 4\n7 3\n1 8\n1 9");
			auto out = ostringstream();
			auto sol = acwing4310();
			sol.main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3\n6\n8\n-1\n9\n4\n", ans);
		}
	}// namespace acwing4310

	namespace acwing84 {
		TEST(acwing84, case1) {
			ASSERT_EQ(55, Solution::getSum(10));
		}
	}// namespace acwing84

	namespace acwing67 {
		TEST(acwing67, case1) {
			vector input = {1, 2, 3, 3, 3, 3, 4, 5};
			ASSERT_EQ(4, Solution::getNumberOfK(input, 3));
		}
	}// namespace acwing67

	namespace acwing53 {
		TEST(acwing53, case1) {
			const vector input  = {1, 2, 3, 4, 5, 6, 7, 8};
			const vector output = {1, 2, 3, 4};
			ASSERT_EQ(output, Solution::getLeastNumbers_Solution(input, 4));
		}
	}// namespace acwing53

	namespace acwing68 {
		TEST(acwing68, case1) {
			vector input = {0, 1, 2, 4};
			ASSERT_EQ(3, Solution::getMissingNumber(input));
		}
	}// namespace acwing68

	namespace acwing75 {
		TEST(acwing75, case1) {
			vector input        = {1, 2, 3, 4};
			const vector output = {3, 4};
			ASSERT_EQ(output, Solution::findNumbersWithSum(input, 7));
		}
	}// namespace acwing75

	namespace acwing51 {
		TEST(acwing51, case1) {
			vector input                     = {1, 2, 3};
			const vector<vector<int>> output = {{1, 2, 3},
			                                    {1, 3, 2},
			                                    {2, 1, 3},
			                                    {2, 3, 1},
			                                    {3, 1, 2},
			                                    {3, 2, 1}};
			ASSERT_EQ(output, Solution::permutation(input));
		}
	}// namespace acwing51

	namespace acwing26 {
		TEST(acwing26, case1) {
			ASSERT_EQ(2, Solution::NumberOf1(9));
		}

		TEST(acwing26, case2) {
			ASSERT_EQ(31, Solution::NumberOf1(-2));
		}
	}// namespace acwing26

	TEST(acwing862, case1) {
		istringstream in("5\n"
		                 "32 1.36 nsyiupnnhc\n"
		                 "18 4.53 fmofzwrah\n"
		                 "33 4.86 wzuymbm\n"
		                 "1 3.93 gtnrwcebt\n"
		                 "31 4.53 gcllxioc");
		auto out = ostringstream();
		acwing862::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("1 3.93 gtnrwcebt\n"
		          "18 4.53 fmofzwrah\n"
		          "31 4.53 gcllxioc\n"
		          "32 1.36 nsyiupnnhc\n"
		          "33 4.86 wzuymbm\n",
		          ans);
	}

	TEST(acwing3412, case1) {
		istringstream in("15 2 3\abacabadabacaba\nba\n1 15\n3 4\n2 14");
		auto out = ostringstream();
		acwing3412::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("4\n0\n3\n", ans);
	}

	TEST(acwing3412, case2) {
		istringstream in("3 5 2\naaa\nbaaab\n1 3\n1 1");
		auto out = ostringstream();
		acwing3412::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("0\n0\n", ans);
	}

	TEST(acwing3412, case3) {
		istringstream in("3 1 1\naaa\na\n1 2");
		auto out = ostringstream();
		acwing3412::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2\n", ans);
	}

	TEST(acwing3346, case1) {
		istringstream in("2 2 11 4 9 7 9\n");
		auto out = ostringstream();
		acwing3346::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("2 2 7", ans);
	}

	namespace acwing3358 {
		TEST(acwing3358, case1) {
			istringstream in("abcdefghijklmnopqrstuvwxyz\n"
			                 "mood");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing3358

	namespace acwing3370 {
		TEST(acwing3370, case1) {
			istringstream in("4\n"
			                 "Mildred born in previous Dragon year from Bessie\n"
			                 "Gretta born in previous Monkey year from Mildred\n"
			                 "Elsie born in next Ox year from Gretta\n"
			                 "Paulina born in next Dog year from Bessie");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("12", ans);
		}

		TEST(acwing3370, case2) {
			istringstream in("10\n"
			                 "Aa born in previous Dog year from Bessie\n"
			                 "Ab born in next Monkey year from Aa\n"
			                 "Ac born in previous Dog year from Bessie\n"
			                 "Ad born in next Monkey year from Ab\n"
			                 "Ae born in next Rat year from Ad\n"
			                 "Af born in next Goat year from Bessie\n"
			                 "Ag born in next Rat year from Ab\n"
			                 "Ah born in next Dog year from Ag\n"
			                 "Elsie born in previous Rabbit year from Ah\n"
			                 "Aj born in previous Monkey year from Ag");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("14", ans);
		}
	}// namespace acwing3370

	namespace acwing3745 {
		TEST(acwing3745, case1) {
			istringstream in("4 0\n"
			                 "1 100 2 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2", ans);
		}

		TEST(acwing3745, case2) {
			istringstream in("4 1\n"
			                 "1 100 2 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}

		TEST(acwing3745, case3) {
			istringstream in("1 1\n"
			                 "0");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1", ans);
		}

		TEST(acwing3745, case4) {
			istringstream in("10 9\n"
			                 "9 9 10 9 9 9 9 9 9 9");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("10", ans);
		}

		TEST(acwing3745, case5) {
			istringstream in("2 1\n"
			                 "1 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1", ans);
		}

		TEST(acwing3745, case6) {
			ostringstream oss;
			oss << 1000 << ' ' << 1000 << endl;
			for(int i = 0; i < 999; i++) {
				oss << 999 << ' ';
			}
			oss << 998;
			istringstream in(oss.str());
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("999", ans);
		}

		TEST(acwing3745, case7) {
			istringstream in("10 10\n"
			                 "0 0 0 0 0 0 0 0 0 0");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1", ans);
		}

		TEST(acwing3745, case8) {
			istringstream in("100 11\n"
			                 "50 54 50 50 50 50 50 50 50 54 50 50 50 50 51 52 54 50 50 50 50 50 50 54 52 50 52 50 50 53 52 50 51 50 50 50 50 50 51 50 52 50 50 53 50 54 50 50 50 54 53 54 50 53 50 50 54 50 50 52 51 50 52 50 51 51 50 50 53 52 52 50 50 50 50 50 50 50 53 51 50 50 50 53 50 50 54 53 50 51 50 53 52 51 50 50 53 50 51 54");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("51", ans);
		}
	}// namespace acwing3745

	namespace acwing1459 {
		TEST(acwing1459, case1) {
			istringstream in("3 4\n"
			                 "4 1 2 3\n"
			                 "4 1 3 2\n"
			                 "4 2 1 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("4", ans);
		}
	}// namespace acwing1459

	namespace acwing1442 {
		TEST(acwing1442, case1) {
			istringstream in("10 7\n"
			                 "hello my name is Bessie and this is my essay");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("hello my\n"
			          "name is\n"
			          "Bessie\n"
			          "and this\n"
			          "is my\n"
			          "essay",
			          ans);
		}
	}// namespace acwing1442

	namespace acwing4314 {
		TEST(acwing4314, case1) {
			istringstream in("6");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1", ans);
		}

		TEST(acwing4314, case2) {
			istringstream in("10");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2", ans);
		}
	}// namespace acwing4314

	namespace acwing4315 {
		TEST(acwing4315, case1) {
			istringstream in("2 8 4 4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3 3 ", ans);
		}

		TEST(acwing4315, case2) {
			istringstream in("1 3 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("4 ", ans);
		}

		TEST(acwing4315, case3) {
			istringstream in("2 3 2 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0 1 ", ans);
		}
	}// namespace acwing4315

	namespace acwing1671 {
		TEST(acwing1671, case1) {
			istringstream in("4\n"
			                 "0 0\n"
			                 "0 1\n"
			                 "1 0\n"
			                 "1 2");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2", ans);
		}
	}// namespace acwing1671

	namespace acwing1659 {
		TEST(acwing1659, case1) {
			istringstream in("14\n10001001000010");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2", ans);
		}
	}// namespace acwing1659

	namespace acwing1714 {
		TEST(acwing1714, case1) {
			istringstream in("10 3\n"
			                 "11 4\n"
			                 "12 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0\n"
			          "10\n"
			          "2\n",
			          ans);
		}
	}// namespace acwing1714

	namespace acwing1695 {
		TEST(acwing1695, case1) {
			istringstream in("3\n"
			                 "1 2 1\n"
			                 "3 2 1\n"
			                 "1 3 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2", ans);
		}
	}// namespace acwing1695

	namespace acwing1683 {
		TEST(acwing1683, case1) {
			istringstream in("4 7 9");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1\n"
			          "2",
			          ans);
		}
	}// namespace acwing1683

	namespace acwing4318 {
		TEST(acwing4318, case1) {
			istringstream in("LLUUUR");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("YES", ans);
		}

		TEST(acwing4318, case2) {
			istringstream in("RRUULLDD");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("NO", ans);
		}
	}// namespace acwing4318

	namespace acwing4319 {
		TEST(acwing4319, case1) {
			istringstream in("6 3\n1 3 9 8 24 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("5", ans);
		}
	}// namespace acwing4319

	namespace acwing1470 {
		TEST(acwing1470, case1) {
			istringstream in("..........\n"
			                 "..........\n"
			                 "..........\n"
			                 "..B.......\n"
			                 "..........\n"
			                 ".....R....\n"
			                 "..........\n"
			                 "..........\n"
			                 ".....L....\n"
			                 "..........");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("7", ans);
		}
	}// namespace acwing1470

	namespace acwing1761 {
		TEST(acwing1761, case1) {
			istringstream in("1 2 3 5\n"
			                 "6 0 10 4\n"
			                 "2 1 8 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("17", ans);
		}
	}// namespace acwing1761

	namespace acwing1749 {
		TEST(acwing1749, case1) {
			istringstream in("2 1 7 4\n"
			                 "5 -1 10 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("15", ans);
		}

		TEST(acwing1749, case2) {
			istringstream in("14 -783 421 693\n"
			                 "-153 680 443 741");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("595441", ans);
		}
	}// namespace acwing1749

	namespace acwing1737 {
		TEST(acwing1737, case1) {
			istringstream in("3 10 8 2");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing1737

	namespace acwing1725 {
		TEST(acwing1725, case1) {
			istringstream in("COW\n"
			                 "XXO\n"
			                 "ABC");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0\n"
			          "2",
			          ans);
		}
	}// namespace acwing1725

	namespace acwing4394 {
		TEST(acwing4394, case1) {
			istringstream in("5 5\n1 2 3 4 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 5", ans);
		}

		TEST(acwing4394, case2) {
			istringstream in("9 3\n6 5 1 2 3 2 1 4 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3 7", ans);
		}

		TEST(acwing4394, case3) {
			istringstream in("3 1\n1 2 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3 3", ans);
		}

		TEST(acwing4394, case4) {
			istringstream in("6 8\n1 1 1 1 1 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 6", ans);
		}
	}// namespace acwing4394

	namespace acwing1812 {
		TEST(acwing1812, case1) {
			istringstream in("6 6 8 8\n"
			                 "1 8 4 9");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("49", ans);
		}
	}// namespace acwing1812

	namespace acwing1800 {
		TEST(acwing1800, case1) {
			istringstream in("10\n"
			                 "Bessie 1\n"
			                 "Maggie 13\n"
			                 "Elsie 3\n"
			                 "Elsie 4\n"
			                 "Henrietta 4\n"
			                 "Gertie 12\n"
			                 "Daisy 7\n"
			                 "Annabelle 10\n"
			                 "Bessie 6\n"
			                 "Henrietta 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Henrietta", ans);
		}
	}// namespace acwing1800

	namespace acwing1788 {
		TEST(acwing1788, case1) {
			istringstream in("8\n"
			                 "3 1\n"
			                 "3 0\n"
			                 "6 0\n"
			                 "2 1\n"
			                 "4 1\n"
			                 "3 0\n"
			                 "4 0\n"
			                 "3 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing1788

	namespace acwing1775 {
		TEST(acwing1775, case1) {
			istringstream in("3 6");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("9", ans);
		}
	}// namespace acwing1775

	namespace acwing785 {
		TEST(acwing785, case1) {
			istringstream in("5\n"
			                 "3 1 2 4 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 2 3 4 5 ", ans);
		}
	}// namespace acwing785

	namespace acwing788 {
		TEST(acwing788, case1) {
			istringstream in("6\n"
			                 "2 3 4 5 6 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("5", ans);
		}

		TEST(acwing788, case2) {
			istringstream in("10\n"
			                 "88 71 16 2 72 38 94 50 72 67");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("21", ans);
		}
	}// namespace acwing788

	namespace acwing789 {
		TEST(acwing789, case1) {
			istringstream in("6 3\n"
			                 "1 2 2 3 3 4\n"
			                 "3\n"
			                 "4\n"
			                 "5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3 4\n"
			          "5 5\n"
			          "-1 -1\n",
			          ans);
		}
	}// namespace acwing789

	namespace acwing1866 {
		TEST(acwing1866, case1) {
			istringstream in("7 10\n"
			                 "4 8");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("6", ans);
		}
	}// namespace acwing1866

	namespace acwing1854 {
		TEST(acwing1854, case1) {
			istringstream in("1 2\n1 1\n1 1\n1 2");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1\n1\n1\n", ans);
		}
	}// namespace acwing1854

	namespace acwing4397 {
		TEST(acwing4397, case2) {
			istringstream in("5 3\n3 4 7 10 3\n4 5 5 12 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("25", ans);
		}
	}// namespace acwing4397

	namespace acwing1842 {
		TEST(acwing1842, case1) {
			istringstream in("17 25 77");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("76", ans);
		}
	}// namespace acwing1842

	namespace acwing1824 {
		TEST(acwing1824, case1) {
			istringstream in("5 3\n"
			                 "1\n"
			                 "6\n"
			                 "4\n"
			                 "3\n"
			                 "1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("4", ans);
		}
	}// namespace acwing1824

	namespace acwing800 {
		TEST(acwing800, case1) {
			istringstream in("4 5 6\n"
			                 "1 2 4 7\n"
			                 "3 4 6 8 9");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 1", ans);
		}
	}// namespace acwing800

	namespace acwing2816 {
		TEST(acwing2816, case1) {
			istringstream in("3 5\n"
			                 "1 3 5\n"
			                 "1 2 3 4 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Yes", ans);
		}
	}// namespace acwing2816

	namespace acwing1902 {
		TEST(acwing1902, case1) {
			istringstream in("4\n"
			                 "0 0\n"
			                 "8 3\n"
			                 "11 -1\n"
			                 "10 0");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("14", ans);
		}
	}// namespace acwing1902

	namespace acwing3302 {
		TEST(acwing3302, case1) {
			istringstream in("(2+2)*(1+1)");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("8", ans);
		}

		TEST(acwing3302, case2) {
			istringstream in("(3+5*4/2+2*(1+1)*(2+2))");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("29", ans);
		}

		TEST(acwing3302, case3) {
			istringstream in("2*10-1000+24-(5*3)+(3*2)");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("-965", ans);
		}
	}// namespace acwing3302

	namespace acwing831 {
		TEST(acwing831, case1) {
			istringstream in("3\n"
			                 "aba\n"
			                 "5\n"
			                 "ababa");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0 2 ", ans);
		}

		TEST(acwing831, case2) {
			istringstream in("10\n"
			                 "jNNNNjNNNN\n"
			                 "30\n"
			                 "jNNPw9NNNNnNMANTNHGNjNNNNjNNNN");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("20 ", ans);
		}

		TEST(acwing831, case3) {
			istringstream in("7\n"
			                 "aabaaaa\n"
			                 "11\n"
			                 "aabaaabaaaa");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("4 ", ans);
		}

		TEST(get_next, case1) {
			const string str  = "ababaa";
			const vector next = {0, 0, 1, 2, 3, 1};
			ASSERT_EQ(next, get_next(str));
		}

		TEST(get_next, case2) {
			const string str  = "ababaaababaa";
			const vector next = {0, 0, 1, 2, 3, 1, 1, 2, 3, 4, 5, 6};
			ASSERT_EQ(next, get_next(str));
		}

		TEST(get_next, case3) {
			const string str  = "aabaaaa";
			const vector next = {0, 1, 0, 1, 2, 2, 2};
			ASSERT_EQ(next, get_next(str));
		}
	}// namespace acwing831

	namespace acwing1892 {
		TEST(acwing1892, case1) {
			istringstream in("1 2 3\n"
			                 "3 3\n"
			                 "3 2 1\n"
			                 "4 4\n"
			                 "2 1 4 3\n"
			                 "8 5\n"
			                 "4 1 7 8 2");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("8", ans);
		}

		TEST(acwing1892, case2) {
			istringstream in("10 4 10\n"
			                 "580 5\n"
			                 "5 3 10 4 7\n"
			                 "282 10\n"
			                 "2 6 4 8 9 3 5 10 7 1\n"
			                 "273 8\n"
			                 "10 6 5 9 7 3 8 4\n"
			                 "379 5\n"
			                 "7 6 10 4 9\n"
			                 "953 3\n"
			                 "2 10 1\n"
			                 "203 5\n"
			                 "9 8 1 6 10\n"
			                 "831 4\n"
			                 "5 10 3 8\n"
			                 "561 8\n"
			                 "7 10 8 2 5 3 6 4\n"
			                 "732 3\n"
			                 "8 2 1\n"
			                 "428 6\n"
			                 "1 7 3 4 2 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("273", ans);
		}
	}// namespace acwing1892

	namespace acwing1883 {
		TEST(acwing1883, case2) {
			istringstream in("whatthemomooofun\n"
			                 "moo");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("whatthefun", ans);
		}
	}// namespace acwing1883

	namespace acwing1995 {
		TEST(acwing1995, case1) {
			istringstream in("4 5\n"
			                 "3 L\n"
			                 "5 R\n"
			                 "1 L\n"
			                 "2 R\n"
			                 "4 R\n"
			                 "1 L\n"
			                 "3 L\n"
			                 "4 R\n"
			                 "2 L");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing1995

	namespace acwing143 {
		TEST(acwing143, case1) {
			istringstream in("3\n"
			                 "1 2 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing143

	namespace acwing837 {
		TEST(acwing837, case1) {
			istringstream in("5 5\n"
			                 "C 1 2\n"
			                 "Q1 1 2\n"
			                 "Q2 1\n"
			                 "C 2 5\n"
			                 "Q2 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Yes\n"
			          "2\n"
			          "3\n",
			          ans);
		}
	}// namespace acwing837

	namespace acwing240 {
		TEST(acwing240, case1) {
			istringstream in("100 7\n"
			                 "1 101 1 \n"
			                 "2 1 2\n"
			                 "2 2 3 \n"
			                 "2 3 3 \n"
			                 "1 1 3 \n"
			                 "2 3 1 \n"
			                 "1 5 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing240

	namespace acwing845 {
		TEST(acwing845, case1) {
			istringstream in("2  3  4  1  5  x  7  6  8");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("19", ans);
		}

		TEST(acwing845, case2) {
			istringstream in("6 4 7 8 5 x 3 2 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("31", ans);
		}
	}// namespace acwing845

	namespace acwing849 {
		TEST(acwing849, case1) {
			istringstream in("3 3\n"
			                 "1 2 2\n"
			                 "2 3 1\n"
			                 "1 3 4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}

		TEST(acwing849, case2) {
			istringstream in("5 10\n"
			                 "1 2 2\n"
			                 "5 3 3\n"
			                 "4 1 8\n"
			                 "2 4 3\n"
			                 "4 5 7\n"
			                 "5 2 3\n"
			                 "3 4 1\n"
			                 "1 2 9\n"
			                 "3 2 3\n"
			                 "1 2 8");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("12", ans);
		}
	}// namespace acwing849

	namespace acwing853 {
		TEST(acwing853, case1) {
			istringstream in("3 3 1\n"
			                 "1 2 1\n"
			                 "2 3 1\n"
			                 "1 3 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}

		TEST(acwing853, case2) {
			istringstream in("10 20 8\n"
			                 "4 2 7\n"
			                 "8 7 10\n"
			                 "1 3 1\n"
			                 "7 6 1\n"
			                 "4 5 8\n"
			                 "8 7 5\n"
			                 "5 7 1\n"
			                 "6 10 2\n"
			                 "3 1 9\n"
			                 "5 4 4\n"
			                 "4 7 1\n"
			                 "9 9 9\n"
			                 "8 1 8\n"
			                 "5 4 5\n"
			                 "7 6 5\n"
			                 "3 7 7\n"
			                 "4 9 1\n"
			                 "2 1 9\n"
			                 "2 9 9\n"
			                 "6 1 -2");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("11", ans);
		}
	}// namespace acwing853

	namespace acwing851 {
		TEST(acwing851, case1) {
			istringstream in("3 3\n"
			                 "1 2 5\n"
			                 "2 3 -3\n"
			                 "1 3 4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2", ans);
		}
	}// namespace acwing851

	namespace acwing852 {
		TEST(acwing852, case1) {
			istringstream in("3 3\n"
			                 "1 2 -1\n"
			                 "2 3 4\n"
			                 "3 1 -4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Yes", ans);
		}

		TEST(acwing852, case2) {
			istringstream in("5 4\n"
			                 "1 2 1\n"
			                 "3 4 -1\n"
			                 "4 5 2\n"
			                 "5 3 -4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Yes", ans);
		}
	}// namespace acwing852
}// namespace acwing
