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

	TEST(acwing672, case3) {
		istringstream in("4520.00");
		auto out = ostringstream();
		acwing672::main(in, out);
		const auto ans = out.str();
		ASSERT_EQ("R$ 355.60", ans);
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
			auto out        = ostringstream();
			auto sol        = Solution();
			auto start_time = chrono::high_resolution_clock::now();
			sol.main(in, out);
			auto end_time = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
			ASSERT_LE(duration, 1000);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}
	}// namespace acwing1929
}// namespace acwing
