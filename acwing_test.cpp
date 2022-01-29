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
}// namespace acwing