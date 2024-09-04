//
// Created by tategotoazarasi on 24-5-7.
//
#include "acwing408.h"
#include "gtest/gtest.h"

namespace acwing {
	namespace acwing3378 {
		TEST(acwing3378, case1) {
			istringstream in("4\n"
			                 "0\n"
			                 "jack 70\n"
			                 "peter 96\n"
			                 "Tom 70\n"
			                 "smith 67");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("peter 96\n"
			          "jack 70\n"
			          "Tom 70\n"
			          "smith 67\n",
			          ans);
		}

		TEST(acwing3378, case2) {
			istringstream in("4\n"
			                 "1\n"
			                 "jack 70\n"
			                 "peter 96\n"
			                 "Tom 70\n"
			                 "smith 67");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("smith 67\n"
			          "jack 70\n"
			          "Tom 70\n"
			          "peter 96\n",
			          ans);
		}

		TEST(acwing3378, case3) {
			istringstream in("100\n"
			                 "0\n"
			                 "ueuauw 39\n"
			                 "rhntqphmbc 50\n"
			                 "gwe 94\n"
			                 "gxym 99\n"
			                 "z 48\n"
			                 "ccugwbcyu 22\n"
			                 "qeo 25\n"
			                 "veqb 25\n"
			                 "fecl 23\n"
			                 "jkakocou 6\n"
			                 "zjf 17\n"
			                 "wmjflfg 68\n"
			                 "qijg 3\n"
			                 "euiuxavbzx 75\n"
			                 "cnnpbsdknk 8\n"
			                 "xzm 50\n"
			                 "zkkteb 34\n"
			                 "dnmmp 40\n"
			                 "pqbqshzbw 69\n"
			                 "j 5\n"
			                 "owqpleza 81\n"
			                 "zxmbfhd 40\n"
			                 "efhufcak 71\n"
			                 "ih 15\n"
			                 "tle 12\n"
			                 "hahmeo 17\n"
			                 "fpaqh 57\n"
			                 "jgaymzbbe 77\n"
			                 "lg 42\n"
			                 "olfyjwvao 35\n"
			                 "ytrrfqpqal 62\n"
			                 "ypdz 34\n"
			                 "eiiplejnht 83\n"
			                 "lcjwld 56\n"
			                 "lrktzp 71\n"
			                 "zxbmu 56\n"
			                 "ayqeet 76\n"
			                 "okkarfg 93\n"
			                 "qg 54\n"
			                 "qnncyeab 62\n"
			                 "ufokdpji 58\n"
			                 "y 71\n"
			                 "seycf 76\n"
			                 "oeuur 100\n"
			                 "iegnj 26\n"
			                 "wejcgx 62\n"
			                 "zbq 91\n"
			                 "weil 71\n"
			                 "mnmjdsbonc 93\n"
			                 "wtwogwzv 51\n"
			                 "opf 76\n"
			                 "y 99\n"
			                 "rcor 61\n"
			                 "pkcvneh 68\n"
			                 "ieuk 27\n"
			                 "sbygxeeot 9\n"
			                 "bywjbi 96\n"
			                 "ngaqiie 38\n"
			                 "moypf 19\n"
			                 "ocvgzccuwm 2\n"
			                 "zmxwoohbx 65\n"
			                 "uq 20\n"
			                 "rwyay 100\n"
			                 "ecl 73\n"
			                 "sxzuc 17\n"
			                 "g 96\n"
			                 "sbhwwec 2\n"
			                 "xladpyjbh 72\n"
			                 "dumtwkm 54\n"
			                 "dganarbzg 1\n"
			                 "kplbvgbfm 52\n"
			                 "xznewvj 74\n"
			                 "qxxoftmvy 26\n"
			                 "btgs 100\n"
			                 "ebpb 59\n"
			                 "rzcjegvaik 19\n"
			                 "c 31\n"
			                 "sufabvfhu 26\n"
			                 "y 39\n"
			                 "hzwcluebji 15\n"
			                 "pleyhlspye 10\n"
			                 "himeyqc 2\n"
			                 "uldwmrr 3\n"
			                 "aqroavrgal 30\n"
			                 "niwkcqpx 79\n"
			                 "idybglq 57\n"
			                 "cobjitjud 11\n"
			                 "wijxnamzgm 55\n"
			                 "lujjwqmf 11\n"
			                 "mqmemhrlxs 59\n"
			                 "e 47\n"
			                 "oktlvt 46\n"
			                 "l 40\n"
			                 "mwjhpryut 7\n"
			                 "s 85\n"
			                 "s 73\n"
			                 "jqf 33\n"
			                 "yjkvuxrlq 1\n"
			                 "ibme 99\n"
			                 "wr 69");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("oeuur 100\n"
			          "rwyay 100\n"
			          "btgs 100\n"
			          "gxym 99\n"
			          "y 99\n"
			          "ibme 99\n"
			          "bywjbi 96\n"
			          "g 96\n"
			          "gwe 94\n"
			          "okkarfg 93\n"
			          "mnmjdsbonc 93\n"
			          "zbq 91\n"
			          "s 85\n"
			          "eiiplejnht 83\n"
			          "owqpleza 81\n"
			          "niwkcqpx 79\n"
			          "jgaymzbbe 77\n"
			          "ayqeet 76\n"
			          "seycf 76\n"
			          "opf 76\n"
			          "euiuxavbzx 75\n"
			          "xznewvj 74\n"
			          "ecl 73\n"
			          "s 73\n"
			          "xladpyjbh 72\n"
			          "efhufcak 71\n"
			          "lrktzp 71\n"
			          "y 71\n"
			          "weil 71\n"
			          "pqbqshzbw 69\n"
			          "wr 69\n"
			          "wmjflfg 68\n"
			          "pkcvneh 68\n"
			          "zmxwoohbx 65\n"
			          "ytrrfqpqal 62\n"
			          "qnncyeab 62\n"
			          "wejcgx 62\n"
			          "rcor 61\n"
			          "ebpb 59\n"
			          "mqmemhrlxs 59\n"
			          "ufokdpji 58\n"
			          "fpaqh 57\n"
			          "idybglq 57\n"
			          "lcjwld 56\n"
			          "zxbmu 56\n"
			          "wijxnamzgm 55\n"
			          "qg 54\n"
			          "dumtwkm 54\n"
			          "kplbvgbfm 52\n"
			          "wtwogwzv 51\n"
			          "rhntqphmbc 50\n"
			          "xzm 50\n"
			          "z 48\n"
			          "e 47\n"
			          "oktlvt 46\n"
			          "lg 42\n"
			          "dnmmp 40\n"
			          "zxmbfhd 40\n"
			          "l 40\n"
			          "ueuauw 39\n"
			          "y 39\n"
			          "ngaqiie 38\n"
			          "olfyjwvao 35\n"
			          "zkkteb 34\n"
			          "ypdz 34\n"
			          "jqf 33\n"
			          "c 31\n"
			          "aqroavrgal 30\n"
			          "ieuk 27\n"
			          "iegnj 26\n"
			          "qxxoftmvy 26\n"
			          "sufabvfhu 26\n"
			          "qeo 25\n"
			          "veqb 25\n"
			          "fecl 23\n"
			          "ccugwbcyu 22\n"
			          "uq 20\n"
			          "moypf 19\n"
			          "rzcjegvaik 19\n"
			          "zjf 17\n"
			          "hahmeo 17\n"
			          "sxzuc 17\n"
			          "ih 15\n"
			          "hzwcluebji 15\n"
			          "tle 12\n"
			          "cobjitjud 11\n"
			          "lujjwqmf 11\n"
			          "pleyhlspye 10\n"
			          "sbygxeeot 9\n"
			          "cnnpbsdknk 8\n"
			          "mwjhpryut 7\n"
			          "jkakocou 6\n"
			          "j 5\n"
			          "qijg 3\n"
			          "uldwmrr 3\n"
			          "ocvgzccuwm 2\n"
			          "sbhwwec 2\n"
			          "himeyqc 2\n"
			          "dganarbzg 1\n"
			          "yjkvuxrlq 1\n",
			          ans);
		}

		TEST(acwing3378, case4) {
			istringstream in("100\n"
			                 "0\n"
			                 "eitqx 37\n"
			                 "gpnwh 96\n"
			                 "gre 7\n"
			                 "t 89\n"
			                 "axgt 77\n"
			                 "bedfrq 14\n"
			                 "wibtck 81\n"
			                 "uvi 95\n"
			                 "fjik 37\n"
			                 "apv 85\n"
			                 "tzyame 55\n"
			                 "avfqpdgj 29\n"
			                 "mgkerlanxu 92\n"
			                 "kip 77\n"
			                 "n 30\n"
			                 "ovcaijgoal 95\n"
			                 "schkm 14\n"
			                 "huga 98\n"
			                 "bvvtz 74\n"
			                 "ba 39\n"
			                 "ean 75\n"
			                 "w 100\n"
			                 "gjtoystw 60\n"
			                 "mcp 27\n"
			                 "yanohhiahb 68\n"
			                 "vuo 14\n"
			                 "hxengkhcog 81\n"
			                 "z 33\n"
			                 "dfhgyfk 16\n"
			                 "rioeptytq 44\n"
			                 "tsx 15\n"
			                 "mwusnru 40\n"
			                 "nne 60\n"
			                 "xg 71\n"
			                 "yqoyso 48\n"
			                 "azpfhcl 98\n"
			                 "swn 26\n"
			                 "u 70\n"
			                 "srjgvxxh 26\n"
			                 "blyob 4\n"
			                 "qcbnyndvpc 67\n"
			                 "trhsghq 68\n"
			                 "edbnpcg 64\n"
			                 "vretjhkq 46\n"
			                 "h 32\n"
			                 "bujfbsbvkx 85\n"
			                 "z 49\n"
			                 "itepoq 18\n"
			                 "namavupy 87\n"
			                 "wbfr 46\n"
			                 "zw 27\n"
			                 "v 6\n"
			                 "lhpqsssir 56\n"
			                 "c 7\n"
			                 "g 12\n"
			                 "i 11\n"
			                 "jj 85\n"
			                 "zicwxfsf 71\n"
			                 "yyedh 19\n"
			                 "sblizpeey 60\n"
			                 "bcwqcv 42\n"
			                 "w 94\n"
			                 "zlvs 78\n"
			                 "olwszucmf 64\n"
			                 "qlhtvus 79\n"
			                 "nbnyavymi 23\n"
			                 "lqzlapfyu 92\n"
			                 "qtpznd 30\n"
			                 "t 85\n"
			                 "xhh 38\n"
			                 "iaxsj 64\n"
			                 "ycwmbpja 92\n"
			                 "d 99\n"
			                 "unt 88\n"
			                 "fzmzqw 89\n"
			                 "aakxmwzb 51\n"
			                 "km 95\n"
			                 "kzjhr 79\n"
			                 "mrrz 80\n"
			                 "yiwp 66\n"
			                 "zlwlwbnz 35\n"
			                 "laexmop 61\n"
			                 "rao 65\n"
			                 "k 76\n"
			                 "qupfnwemav 93\n"
			                 "er 20\n"
			                 "xoltw 30\n"
			                 "xxnnylhmr 81\n"
			                 "o 66\n"
			                 "hnwdhujn 73\n"
			                 "zwjkxq 14\n"
			                 "ejibwqo 22\n"
			                 "d 20\n"
			                 "imshoxcv 93\n"
			                 "axygtftzrq 65\n"
			                 "p 53\n"
			                 "lrzhstv 54\n"
			                 "lezed 51\n"
			                 "hs 64\n"
			                 "gz 52");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("w 100\n"
			          "d 99\n"
			          "huga 98\n"
			          "azpfhcl 98\n"
			          "gpnwh 96\n"
			          "uvi 95\n"
			          "ovcaijgoal 95\n"
			          "km 95\n"
			          "w 94\n"
			          "qupfnwemav 93\n"
			          "imshoxcv 93\n"
			          "mgkerlanxu 92\n"
			          "lqzlapfyu 92\n"
			          "ycwmbpja 92\n"
			          "t 89\n"
			          "fzmzqw 89\n"
			          "unt 88\n"
			          "namavupy 87\n"
			          "apv 85\n"
			          "bujfbsbvkx 85\n"
			          "jj 85\n"
			          "t 85\n"
			          "wibtck 81\n"
			          "hxengkhcog 81\n"
			          "xxnnylhmr 81\n"
			          "mrrz 80\n"
			          "qlhtvus 79\n"
			          "kzjhr 79\n"
			          "zlvs 78\n"
			          "axgt 77\n"
			          "kip 77\n"
			          "k 76\n"
			          "ean 75\n"
			          "bvvtz 74\n"
			          "hnwdhujn 73\n"
			          "xg 71\n"
			          "zicwxfsf 71\n"
			          "u 70\n"
			          "yanohhiahb 68\n"
			          "trhsghq 68\n"
			          "qcbnyndvpc 67\n"
			          "yiwp 66\n"
			          "o 66\n"
			          "rao 65\n"
			          "axygtftzrq 65\n"
			          "edbnpcg 64\n"
			          "olwszucmf 64\n"
			          "iaxsj 64\n"
			          "hs 64\n"
			          "laexmop 61\n"
			          "gjtoystw 60\n"
			          "nne 60\n"
			          "sblizpeey 60\n"
			          "lhpqsssir 56\n"
			          "tzyame 55\n"
			          "lrzhstv 54\n"
			          "p 53\n"
			          "gz 52\n"
			          "aakxmwzb 51\n"
			          "lezed 51\n"
			          "z 49\n"
			          "yqoyso 48\n"
			          "vretjhkq 46\n"
			          "wbfr 46\n"
			          "rioeptytq 44\n"
			          "bcwqcv 42\n"
			          "mwusnru 40\n"
			          "ba 39\n"
			          "xhh 38\n"
			          "eitqx 37\n"
			          "fjik 37\n"
			          "zlwlwbnz 35\n"
			          "z 33\n"
			          "h 32\n"
			          "n 30\n"
			          "qtpznd 30\n"
			          "xoltw 30\n"
			          "avfqpdgj 29\n"
			          "mcp 27\n"
			          "zw 27\n"
			          "swn 26\n"
			          "srjgvxxh 26\n"
			          "nbnyavymi 23\n"
			          "ejibwqo 22\n"
			          "er 20\n"
			          "d 20\n"
			          "yyedh 19\n"
			          "itepoq 18\n"
			          "dfhgyfk 16\n"
			          "tsx 15\n"
			          "bedfrq 14\n"
			          "schkm 14\n"
			          "vuo 14\n"
			          "zwjkxq 14\n"
			          "g 12\n"
			          "i 11\n"
			          "gre 7\n"
			          "c 7\n"
			          "v 6\n"
			          "blyob 4\n",
			          ans);
		}
	}// namespace acwing3378

	namespace acwing3376 {
		TEST(acwing3376, case1) {
			istringstream in("3\n"
			                 "1 90\n"
			                 "2 87\n"
			                 "3 92");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2 87\n"
			          "1 90\n"
			          "3 92\n",
			          ans);
		}
	}// namespace acwing3376

	namespace acwing3374 {
		TEST(acwing3374, case1) {
			istringstream in("10 2\n"
			                 "11");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1011",
			          ans);
		}

		TEST(acwing3374, case2) {
			istringstream in("33 32\n"
			                 "8MJ8REPCCDS646V91FU5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("fil22vqticlaaeabeme7",
			          ans);
		}
	}// namespace acwing3374

	namespace acwing3757 {
		TEST(acwing3757, case1) {
			auto head = new ListNode{1,
			                         new ListNode{2,
			                                      new ListNode{3,
			                                                   new ListNode{4, nullptr}}}};
			rearrangedList(head);
			ASSERT_EQ(1, head->val);
			ASSERT_EQ(4, head->next->val);
			ASSERT_EQ(2, head->next->next->val);
			ASSERT_EQ(3, head->next->next->next->val);
			delete head->next->next->next;
			delete head->next->next;
			delete head->next;
			delete head;
		}

		TEST(acwing3757, case2) {
			auto head = new ListNode{1,
			                         new ListNode{2,
			                                      new ListNode{3,
			                                                   new ListNode{4,
			                                                                new ListNode{5, nullptr}}}}};
			rearrangedList(head);
			ASSERT_EQ(1, head->val);
			ASSERT_EQ(5, head->next->val);
			ASSERT_EQ(2, head->next->next->val);
			ASSERT_EQ(4, head->next->next->next->val);
			ASSERT_EQ(3, head->next->next->next->next->val);
			delete head->next->next->next->next;
			delete head->next->next->next;
			delete head->next->next;
			delete head->next;
			delete head;
		}
	}// namespace acwing3757

	namespace acwing3607 {
		TEST(acwing3607, case1) {
			istringstream in("2000 3\n"
			                 "2000 31\n"
			                 "2000 40\n"
			                 "2000 60\n"
			                 "2000 61\n"
			                 "2001 60");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2000-01-03\n"
			          "2000-01-31\n"
			          "2000-02-09\n"
			          "2000-02-29\n"
			          "2000-03-01\n"
			          "2001-03-01\n",
			          ans);
		}

		TEST(acwing3607, case2) {
			istringstream in("2000 3\n"
			                 "2000 31\n"
			                 "2000 40\n"
			                 "2000 60\n"
			                 "2000 366\n"
			                 "2001 60\n"
			                 "2004 366\n"
			                 "1900 365");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2000-01-03\n"
			          "2000-01-31\n"
			          "2000-02-09\n"
			          "2000-02-29\n"
			          "2000-12-31\n"
			          "2001-03-01\n"
			          "2004-12-31\n"
			          "1900-12-31\n",
			          ans);
		}
	}// namespace acwing3607

	namespace acwing3573 {
		TEST(acwing3573, case1) {
			istringstream in("1\n"
			                 "2008 2 3 100");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2008-05-13\n",
			          ans);
		}

		TEST(acwing3573, case2) {
			istringstream in("154\n"
			                 "1940 8 14 88\n"
			                 "2261 4 14 67\n"
			                 "2181 5 20 55\n"
			                 "1321 1 11 65\n"
			                 "1817 9 20 16\n"
			                 "2027 4 28 46\n"
			                 "1890 10 16 92\n"
			                 "2913 2 21 22\n"
			                 "1784 9 1 67\n"
			                 "2921 11 29 19\n"
			                 "2846 7 28 87\n"
			                 "2906 12 20 81\n"
			                 "1761 11 20 53\n"
			                 "1537 12 10 83\n"
			                 "2645 5 14 63\n"
			                 "1973 12 30 36\n"
			                 "2604 2 23 19\n"
			                 "2925 10 26 16\n"
			                 "2188 8 14 95\n"
			                 "1722 12 21 44\n"
			                 "2124 9 2 81\n"
			                 "2950 9 16 1\n"
			                 "2742 9 20 5\n"
			                 "2144 1 6 22\n"
			                 "2666 5 12 83\n"
			                 "1051 1 17 5\n"
			                 "2327 4 5 23\n"
			                 "1846 9 18 54\n"
			                 "2615 4 18 7\n"
			                 "1024 4 9 74\n"
			                 "1048 3 9 58\n"
			                 "1977 7 25 79\n"
			                 "1339 9 26 65\n"
			                 "1315 6 19 62\n"
			                 "1403 7 27 19\n"
			                 "1986 11 1 97\n"
			                 "1225 1 17 42\n"
			                 "2419 5 25 79\n"
			                 "1317 12 9 49\n"
			                 "1131 3 16 71\n"
			                 "2045 2 14 99\n"
			                 "1581 12 24 33\n"
			                 "2403 1 6 51\n"
			                 "1853 10 17 16\n"
			                 "2653 7 28 2\n"
			                 "1813 10 23 4\n"
			                 "1137 7 14 89\n"
			                 "2279 7 14 99\n"
			                 "2911 7 15 26\n"
			                 "1895 3 23 95\n"
			                 "1651 12 2 44\n"
			                 "2321 4 7 67\n"
			                 "1796 10 9 65\n"
			                 "1287 5 22 90\n"
			                 "2579 12 3 48\n"
			                 "1883 8 22 87\n"
			                 "2701 1 11 99\n"
			                 "1227 2 9 63\n"
			                 "1476 4 25 57\n"
			                 "2682 5 7 83\n"
			                 "2192 11 17 98\n"
			                 "2337 12 13 76\n"
			                 "2594 5 23 45\n"
			                 "2473 2 2 77\n"
			                 "2779 2 22 22\n"
			                 "1576 4 15 62\n"
			                 "2514 7 31 26\n"
			                 "2086 5 5 6\n"
			                 "1497 10 16 39\n"
			                 "2081 11 10 61\n"
			                 "1413 4 29 49\n"
			                 "2602 2 4 49\n"
			                 "2467 5 29 15\n"
			                 "1639 8 9 42\n"
			                 "1370 10 20 12\n"
			                 "1006 5 22 31\n"
			                 "1984 2 17 15\n"
			                 "1365 2 22 79\n"
			                 "1120 12 9 27\n"
			                 "2641 4 26 25\n"
			                 "1868 10 1 36\n"
			                 "2542 11 28 89\n"
			                 "2038 1 11 87\n"
			                 "1976 2 25 72\n"
			                 "1757 6 11 55\n"
			                 "2754 9 21 49\n"
			                 "2500 9 23 34\n"
			                 "1218 5 5 83\n"
			                 "2909 9 24 66\n"
			                 "1570 11 3 61\n"
			                 "1652 1 8 88\n"
			                 "1837 12 10 98\n"
			                 "2999 11 30 4\n"
			                 "2941 8 18 56\n"
			                 "1109 12 6 94\n"
			                 "1249 5 31 72\n"
			                 "1125 3 13 72\n"
			                 "2936 11 3 24\n"
			                 "2240 6 30 97\n"
			                 "2134 4 24 72\n"
			                 "1979 1 23 50\n"
			                 "2638 2 9 67\n"
			                 "2695 2 27 20\n"
			                 "1738 10 10 92\n"
			                 "2749 5 3 70\n"
			                 "1794 9 13 19\n"
			                 "1607 7 2 74\n"
			                 "1118 4 23 99\n"
			                 "2516 8 14 48\n"
			                 "1680 7 19 79\n"
			                 "2351 4 27 77\n"
			                 "1644 6 24 23\n"
			                 "1508 3 3 45\n"
			                 "1361 4 1 78\n"
			                 "2961 8 8 90\n"
			                 "2316 1 7 29\n"
			                 "1193 2 24 62\n"
			                 "1132 3 17 12\n"
			                 "2232 12 13 37\n"
			                 "1911 9 20 40\n"
			                 "1785 3 27 56\n"
			                 "1038 7 22 67\n"
			                 "1361 4 7 52\n"
			                 "1410 12 19 89\n"
			                 "1092 8 25 84\n"
			                 "1852 4 27 20\n"
			                 "1768 8 31 31\n"
			                 "2451 7 7 48\n"
			                 "1090 9 27 1\n"
			                 "1349 3 14 98\n"
			                 "2694 5 1 97\n"
			                 "1242 10 25 66\n"
			                 "2826 5 1 83\n"
			                 "1172 9 9 71\n"
			                 "1079 12 31 62\n"
			                 "1731 10 20 20\n"
			                 "1548 1 11 42\n"
			                 "1180 8 22 43\n"
			                 "1162 1 4 85\n"
			                 "1037 8 14 28\n"
			                 "1610 4 18 59\n"
			                 "2001 8 28 35\n"
			                 "1898 1 11 46\n"
			                 "1085 2 11 90\n"
			                 "1409 10 11 65\n"
			                 "1920 3 31 58\n"
			                 "2341 10 23 28\n"
			                 "1180 12 23 33\n"
			                 "1701 10 1 16\n"
			                 "2621 2 4 33\n"
			                 "2141 10 7 6\n"
			                 "1057 8 27 55\n"
			                 "2489 2 2 93\n"
			                 "1993 7 3 55");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1940-11-10\n"
			          "2261-06-20\n"
			          "2181-07-14\n"
			          "1321-03-17\n"
			          "1817-10-06\n"
			          "2027-06-13\n"
			          "1891-01-16\n"
			          "2913-03-15\n"
			          "1784-11-07\n"
			          "2921-12-18\n"
			          "2846-10-23\n"
			          "2907-03-11\n"
			          "1762-01-12\n"
			          "1538-03-03\n"
			          "2645-07-16\n"
			          "1974-02-04\n"
			          "2604-03-13\n"
			          "2925-11-11\n"
			          "2188-11-17\n"
			          "1723-02-03\n"
			          "2124-11-22\n"
			          "2950-09-17\n"
			          "2742-09-25\n"
			          "2144-01-28\n"
			          "2666-08-03\n"
			          "1051-01-22\n"
			          "2327-04-28\n"
			          "1846-11-11\n"
			          "2615-04-25\n"
			          "1024-06-22\n"
			          "1048-05-06\n"
			          "1977-10-12\n"
			          "1339-11-30\n"
			          "1315-08-20\n"
			          "1403-08-15\n"
			          "1987-02-06\n"
			          "1225-02-28\n"
			          "2419-08-12\n"
			          "1318-01-27\n"
			          "1131-05-26\n"
			          "2045-05-24\n"
			          "1582-01-26\n"
			          "2403-02-26\n"
			          "1853-11-02\n"
			          "2653-07-30\n"
			          "1813-10-27\n"
			          "1137-10-11\n"
			          "2279-10-21\n"
			          "2911-08-10\n"
			          "1895-06-26\n"
			          "1652-01-15\n"
			          "2321-06-13\n"
			          "1796-12-13\n"
			          "1287-08-20\n"
			          "2580-01-20\n"
			          "1883-11-17\n"
			          "2701-04-20\n"
			          "1227-04-13\n"
			          "1476-06-21\n"
			          "2682-07-29\n"
			          "2193-02-23\n"
			          "2338-02-27\n"
			          "2594-07-07\n"
			          "2473-04-20\n"
			          "2779-03-16\n"
			          "1576-06-16\n"
			          "2514-08-26\n"
			          "2086-05-11\n"
			          "1497-11-24\n"
			          "2082-01-10\n"
			          "1413-06-17\n"
			          "2602-03-25\n"
			          "2467-06-13\n"
			          "1639-09-20\n"
			          "1370-11-01\n"
			          "1006-06-22\n"
			          "1984-03-03\n"
			          "1365-05-12\n"
			          "1121-01-05\n"
			          "2641-05-21\n"
			          "1868-11-06\n"
			          "2543-02-25\n"
			          "2038-04-08\n"
			          "1976-05-07\n"
			          "1757-08-05\n"
			          "2754-11-09\n"
			          "2500-10-27\n"
			          "1218-07-27\n"
			          "2909-11-29\n"
			          "1571-01-03\n"
			          "1652-04-05\n"
			          "1838-03-18\n"
			          "2999-12-04\n"
			          "2941-10-13\n"
			          "1110-03-10\n"
			          "1249-08-11\n"
			          "1125-05-24\n"
			          "2936-11-27\n"
			          "2240-10-05\n"
			          "2134-07-05\n"
			          "1979-03-14\n"
			          "2638-04-17\n"
			          "2695-03-19\n"
			          "1739-01-10\n"
			          "2749-07-12\n"
			          "1794-10-02\n"
			          "1607-09-14\n"
			          "1118-07-31\n"
			          "2516-10-01\n"
			          "1680-10-06\n"
			          "2351-07-13\n"
			          "1644-07-17\n"
			          "1508-04-17\n"
			          "1361-06-18\n"
			          "2961-11-06\n"
			          "2316-02-05\n"
			          "1193-04-27\n"
			          "1132-03-29\n"
			          "2233-01-19\n"
			          "1911-10-30\n"
			          "1785-05-22\n"
			          "1038-09-27\n"
			          "1361-05-29\n"
			          "1411-03-18\n"
			          "1092-11-17\n"
			          "1852-05-17\n"
			          "1768-10-01\n"
			          "2451-08-24\n"
			          "1090-09-28\n"
			          "1349-06-20\n"
			          "2694-08-06\n"
			          "1242-12-30\n"
			          "2826-07-23\n"
			          "1172-11-19\n"
			          "1080-03-02\n"
			          "1731-11-09\n"
			          "1548-02-22\n"
			          "1180-10-04\n"
			          "1162-03-30\n"
			          "1037-09-11\n"
			          "1610-06-16\n"
			          "2001-10-02\n"
			          "1898-02-26\n"
			          "1085-05-12\n"
			          "1409-12-15\n"
			          "1920-05-28\n"
			          "2341-11-20\n"
			          "1181-01-25\n"
			          "1701-10-17\n"
			          "2621-03-09\n"
			          "2141-10-13\n"
			          "1057-10-21\n"
			          "2489-05-06\n"
			          "1993-08-27\n",
			          ans);
		}
	}// namespace acwing3573

	namespace acwing3302_408 {
		TEST(acwing3302_408, case1) {
			istringstream in("(2+2)*(1+1)");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("8",
			          ans);
		}

		TEST(acwing3302_408, case2) {
			istringstream in("(3+5*4/2+2*(1+1)*(2+2))");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("29", ans);
		}

		TEST(acwing3302_408, case3) {
			istringstream in("2*10-1000+24-(5*3)+(3*2)");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("-965", ans);
		}
	}// namespace acwing3302_408

	namespace acwing148 {
		TEST(acwing148, case1) {
			istringstream in("3 \n"
			                 "1 2 9 ");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("15", ans);
		}
	}// namespace acwing148

	namespace acwing836_408 {
		TEST(acwing836_408, case1) {
			istringstream in("4 5\n"
			                 "M 1 2\n"
			                 "M 3 4\n"
			                 "Q 1 2\n"
			                 "Q 1 3\n"
			                 "Q 3 4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Yes\n"
			          "No\n"
			          "Yes\n",
			          ans);
		}
	}// namespace acwing836_408

	/**
	 * @brief 3786. 二叉排序树
	 */
	namespace acwing3786 {
		TEST(acwing3786, case1) {
			istringstream in("6\n"
			                 "1 1\n"
			                 "1 3\n"
			                 "1 5\n"
			                 "3 4\n"
			                 "2 3\n"
			                 "4 2");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3\n"
			          "5\n",
			          ans);
		}

		TEST(acwing3786, case2) {
			istringstream in("20\n"
			                 "1 -9\n"
			                 "1 5\n"
			                 "2 5\n"
			                 "2 -9\n"
			                 "1 -5\n"
			                 "1 -4\n"
			                 "4 -19\n"
			                 "1 -10\n"
			                 "2 -4\n"
			                 "2 -10\n"
			                 "1 -14\n"
			                 "4 -17\n"
			                 "4 -10\n"
			                 "2 -14\n"
			                 "1 -12\n"
			                 "1 -3\n"
			                 "3 -8\n"
			                 "1 -7\n"
			                 "4 -18\n"
			                 "1 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("-5\n"
			          "-14\n"
			          "-5\n"
			          "-12\n"
			          "-12\n",
			          ans);
		}
	}// namespace acwing3786

	/**
	 * @brief 149. 荷马史诗
	 */
	namespace acwing149 {
		TEST(acwing149, case1) {
			istringstream in("4 2\n"
			                 "1\n"
			                 "1\n"
			                 "2\n"
			                 "2");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("12\n"
			          "2\n",
			          ans);
		}

		TEST(acwing149, case2) {
			istringstream in("3 2\n"
			                 "1\n"
			                 "2\n"
			                 "3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("9\n"
			          "2\n",
			          ans);
		}

		TEST(acwing149, case3) {
			istringstream in("16 3\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98\n"
			                 "98");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("4214\n"
			          "3\n",
			          ans);
		}
	}// namespace acwing149

	/**
	 * @brief 831. KMP字符串
	 */
	namespace acwing831_408 {
		TEST(acwing831_408, case1) {
			istringstream in("3\n"
			                 "aba\n"
			                 "5\n"
			                 "ababa");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0 2 ",
			          ans);
		}
	}// namespace acwing831_408

	/**
	 * @brief 3385. 玛雅人的密码
	 */
	namespace acwing3385 {
		TEST(acwing3385, case1) {
			istringstream in("5\n"
			                 "02120\n");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1",
			          ans);
		}
	}// namespace acwing3385

	/**
	 * @brief 3429. 全排列
	 */
	namespace acwing3429 {
		TEST(acwing3429, case1) {
			istringstream in("abc");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("abc\n"
			          "acb\n"
			          "bac\n"
			          "bca\n"
			          "cab\n"
			          "cba\n",
			          ans);
		}
	}// namespace acwing3429

	/**
	 * @brief 858. Prim算法求最小生成树
	 */
	namespace acwing858_408 {
		TEST(acwing858_408, case1) {
			istringstream in("4 5\n"
			                 "1 2 1\n"
			                 "1 3 2\n"
			                 "1 4 3\n"
			                 "2 3 2\n"
			                 "3 4 4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("6", ans);
		}
	}// namespace acwing858_408

	/**
	 * @brief 849. Dijkstra求最短路 I
	 */
	namespace acwing849_408 {
		TEST(acwing849_408, case1) {
			istringstream in("3 3\n"
			                 "1 2 2\n"
			                 "2 3 1\n"
			                 "1 3 4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}

		TEST(acwing849_408, case2) {
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
	}// namespace acwing849_408

	/**
	 * @brief 854. Floyd求最短路
	 */
	namespace acwing854_408 {
		TEST(acwing854_408, case1) {
			istringstream in("3 3 2\n"
			                 "1 2 1\n"
			                 "2 3 2\n"
			                 "1 3 1\n"
			                 "2 1\n"
			                 "1 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("impossible\n"
			          "1\n",
			          ans);
		}
	}// namespace acwing854_408

	/**
	 * @brief 848. 有向图的拓扑序列
	 */
	namespace acwing848_408 {
		TEST(acwing848_408, case1) {
			istringstream in("3 3\n"
			                 "1 2\n"
			                 "2 3\n"
			                 "1 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 2 3 ",
			          ans);
		}

		TEST(acwing848_408, case2) {
			istringstream in("5 10\n"
			                 "2 3\n"
			                 "2 5\n"
			                 "2 5\n"
			                 "1 4\n"
			                 "2 4\n"
			                 "1 2\n"
			                 "2 3\n"
			                 "2 4\n"
			                 "3 5\n"
			                 "3 4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 2 3 4 5 ",
			          ans);
		}

		TEST(acwing848_408, case3) {
			istringstream in("10 20\n"
			                 "2 3\n"
			                 "5 10\n"
			                 "1 5\n"
			                 "2 5\n"
			                 "4 6\n"
			                 "1 2\n"
			                 "4 5\n"
			                 "3 7\n"
			                 "2 10\n"
			                 "4 4\n"
			                 "1 7\n"
			                 "1 2\n"
			                 "1 4\n"
			                 "3 8\n"
			                 "7 8\n"
			                 "1 2\n"
			                 "2 5\n"
			                 "4 7\n"
			                 "2 9\n"
			                 "3 10");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("-1",
			          ans);
		}

		TEST(acwing848_408, case4) {
			istringstream in("4 4\n"
			                 "2 1\n"
			                 "1 3\n"
			                 "1 4\n"
			                 "3 4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2 1 3 4 ",
			          ans);
		}
	}// namespace acwing848_408

	/**
	 * @brief 3402. 等差数列
	 */
	namespace acwing3402 {
		TEST(acwing3402, case1) {
			istringstream in("3 4\n"
			                 "1 2 0 0\n"
			                 "0 0 0 0\n"
			                 "3 0 0 0");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 3 3\n"
			          "1 4 4\n"
			          "2 1 2\n",
			          ans);
		}
	}// namespace acwing3402

	/**
	 * @brief 3472. 八皇后
	 */
	namespace acwing3472 {
		TEST(acwing3472, case1) {
			istringstream in("2\n"
			                 "1\n"
			                 "92");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("15863724\n"
			          "84136275\n",
			          ans);
		}
	}// namespace acwing3472

	/**
	 * @brief 3439. 首字母大写
	 */
	namespace acwing3439 {
		TEST(acwing3439, case1) {
			istringstream in("if so, you already have a google account. you can sign in on the right.");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("If So, You Already Have A Google Account. You Can Sign In On The Right.",
			          ans);
		}

		TEST(acwing3439, case2) {
			istringstream in("Lke IioARt mXN bAqKm yzIU oiG wcczrp   W Qr j  auy   iL lMtAfH  CEVaj ni JPoWl  DcUMiqmNMGJ  p hs a");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Lke IioARt MXN BAqKm YzIU OiG Wcczrp   W Qr J  Auy   IL LMtAfH  CEVaj Ni JPoWl  DcUMiqmNMGJ  P Hs A",
			          ans);
		}
	}// namespace acwing3439

	/**
	 * @brief 3379. 反序输出
	 */
	namespace acwing3379 {
		TEST(acwing3379, case1) {
			istringstream in("Upin\n"
			                 "cvYj\n"
			                 "WJpw\n"
			                 "cXOA");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("nipU\n"
			          "jYvc\n"
			          "wpJW\n"
			          "AOXc\n",
			          ans);
		}
	}// namespace acwing3379

	/**
	 * @brief 3390. 特殊乘法
	 */
	namespace acwing3390 {
		TEST(acwing3390, case1) {
			istringstream in("123 45");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("54", ans);
		}
	}// namespace acwing3390

	/**
	 * @brief 3397. 众数
	 */
	namespace acwing3397 {
		TEST(acwing3397, case1) {
			istringstream in("3 2\n"
			                 "31 32 30");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0\n"
			          "3\n",
			          ans);
		}
	}// namespace acwing3397

	/**
	 * @brief 3426. 糖果分享游戏
	 */
	namespace acwing3426 {
		TEST(acwing3426, case1) {
			istringstream in("6\n"
			                 "36\n"
			                 "2\n"
			                 "2\n"
			                 "2\n"
			                 "2\n"
			                 "2\n"
			                 "11\n"
			                 "22\n"
			                 "20\n"
			                 "18\n"
			                 "16\n"
			                 "14\n"
			                 "12\n"
			                 "10\n"
			                 "8\n"
			                 "6\n"
			                 "4\n"
			                 "2\n"
			                 "4\n"
			                 "2\n"
			                 "4\n"
			                 "6\n"
			                 "8\n"
			                 "0");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("15 14\n"
			          "17 22\n"
			          "4 8\n",
			          ans);
		}
	}// namespace acwing3426

	/**
	 * @brief 3406. 日志排序
	 */
	namespace acwing3406 {
		TEST(acwing3406, case1) {
			istringstream in("hs_10000_p   2007-01-17 19:22:53,315     253.035(s)\n"
			                 "hs_10001_p   2007-01-17 19:22:53,315     253.846(s)\n"
			                 "hs_10002_m   2007-01-17 19:22:53,315     129.574(s)\n"
			                 "hs_10002_p   2007-01-17 19:22:53,315     262.531(s)\n"
			                 "hs_10003_m   2007-01-17 19:22:53,318     126.622(s)\n"
			                 "hs_10003_p   2007-01-17 19:22:53,318     136.962(s)\n"
			                 "hs_10005_m   2007-01-17 19:22:53,318     130.487(s)\n"
			                 "hs_10005_p   2007-01-17 19:22:53,318     253.035(s)\n"
			                 "hs_10006_m   2007-01-17 19:22:53,318     248.548(s)\n"
			                 "hs_10006_p   2007-01-17 19:25:23,367    3146.827(s)");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("hs_10003_m   2007-01-17 19:22:53,318     126.622(s)\n"
			          "hs_10002_m   2007-01-17 19:22:53,315     129.574(s)\n"
			          "hs_10005_m   2007-01-17 19:22:53,318     130.487(s)\n"
			          "hs_10003_p   2007-01-17 19:22:53,318     136.962(s)\n"
			          "hs_10006_m   2007-01-17 19:22:53,318     248.548(s)\n"
			          "hs_10000_p   2007-01-17 19:22:53,315     253.035(s)\n"
			          "hs_10005_p   2007-01-17 19:22:53,318     253.035(s)\n"
			          "hs_10001_p   2007-01-17 19:22:53,315     253.846(s)\n"
			          "hs_10002_p   2007-01-17 19:22:53,315     262.531(s)\n"
			          "hs_10006_p   2007-01-17 19:25:23,367    3146.827(s)\n",
			          ans);
		}

		TEST(acwing3406, case2) {
			istringstream in("hs_10000_p   2007-01-17 19:22:53,315     253.035(s)\n"
			                 "hs_10001_p   2007-01-17 19:22:53,315     253.846(s)\n"
			                 "hs_10002_m   2007-01-17 19:22:53,315     129.574(s)\n"
			                 "hs_10002_p   2007-01-17 19:22:53,315     262.531(s)\n"
			                 "hs_10003_m   2007-01-17 19:22:53,318     126.622(s)\n"
			                 "hs_10003_p   2007-01-17 19:22:53,318     136.962(s)\n"
			                 "hs_10005_m   2007-01-17 19:22:53,318     130.487(s)\n"
			                 "hs_10005_p   2007-01-17 19:22:53,318     253.035(s)\n"
			                 "hs_10006_m   2007-01-17 19:22:53,318     248.548(s)\n"
			                 "hs_10006_p   2007-01-17 19:25:23,367    3146.827(s)\n"
			                 "hs_10000_x   2007-01-17 19:22:52,315     253.035(s)\n"
			                 "hs_10000_y   2007-01-17 19:20:53,315     253.035(s)\n"
			                 "hs_10000_z   2007-01-17 18:22:53,315     253.035(s)\n"
			                 "hs_10000_q   2007-01-16 19:22:53,315     253.035(s)\n"
			                 "hs_10000_r   2007-02-17 19:22:53,315     253.035(s)\n"
			                 "hs_10000_s   2008-01-17 19:22:53,315     253.035(s)");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("hs_10003_m   2007-01-17 19:22:53,318     126.622(s)\n"
			          "hs_10002_m   2007-01-17 19:22:53,315     129.574(s)\n"
			          "hs_10005_m   2007-01-17 19:22:53,318     130.487(s)\n"
			          "hs_10003_p   2007-01-17 19:22:53,318     136.962(s)\n"
			          "hs_10006_m   2007-01-17 19:22:53,318     248.548(s)\n"
			          "hs_10000_q   2007-01-16 19:22:53,315     253.035(s)\n"
			          "hs_10000_z   2007-01-17 18:22:53,315     253.035(s)\n"
			          "hs_10000_y   2007-01-17 19:20:53,315     253.035(s)\n"
			          "hs_10000_x   2007-01-17 19:22:52,315     253.035(s)\n"
			          "hs_10000_p   2007-01-17 19:22:53,315     253.035(s)\n"
			          "hs_10005_p   2007-01-17 19:22:53,318     253.035(s)\n"
			          "hs_10000_r   2007-02-17 19:22:53,315     253.035(s)\n"
			          "hs_10000_s   2008-01-17 19:22:53,315     253.035(s)\n"
			          "hs_10001_p   2007-01-17 19:22:53,315     253.846(s)\n"
			          "hs_10002_p   2007-01-17 19:22:53,315     262.531(s)\n"
			          "hs_10006_p   2007-01-17 19:25:23,367    3146.827(s)\n",
			          ans);
		}
	}// namespace acwing3406

	/**
	 * @brief 3447. 子串计算
	 */
	namespace acwing3447 {
		TEST(acwing3447, case1) {
			istringstream in("10101");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0 2\n"
			          "01 2\n"
			          "1 3\n"
			          "10 2\n"
			          "101 2\n",
			          ans);
		}
	}// namespace acwing3447

	/**
	 * @brief 3820. 未出现过的最小正整数
	 */
	namespace acwing3820 {
		TEST(acwing3820, case1) {
			vector<int> in = {-5, 3, 2, 3};
			findMissMin(in);
			ASSERT_EQ(findMissMin(in), 1);
		}

		TEST(acwing3820, case2) {
			vector<int> in = {1, 2, 3};
			findMissMin(in);
			ASSERT_EQ(findMissMin(in), 4);
		}
	}// namespace acwing3820

	/**
	 * @brief 840. 模拟散列表
	 */
	namespace acwing840_408 {
		TEST(acwing840_408, case2) {
			istringstream in("5\n"
			                 "I 1\n"
			                 "I 2\n"
			                 "I 3\n"
			                 "Q 2\n"
			                 "Q 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("Yes\n"
			          "No\n",
			          ans);
		}
	}// namespace acwing840_408

	/**
	 * @brief 3542. 查找
	 */
	namespace acwing3542 {
		TEST(acwing3542, case1) {
			istringstream in("5\n"
			                 "1 5 2 4 3\n"
			                 "3\n"
			                 "2 5 6");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("YES\n"
			          "YES\n"
			          "NO\n",
			          ans);
		}
	}// namespace acwing3542

	/**
	 * @brief 3581. 单词识别
	 */
	namespace acwing3581 {
		TEST(acwing3542, case1) {
			istringstream in("A blockhouse is a small castle that has four openings through which to shoot.");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("a:2\n"
			          "blockhouse:1\n"
			          "castle:1\n"
			          "four:1\n"
			          "has:1\n"
			          "is:1\n"
			          "openings:1\n"
			          "shoot:1\n"
			          "small:1\n"
			          "that:1\n"
			          "through:1\n"
			          "to:1\n"
			          "which:1\n",
			          ans);
		}

		TEST(acwing3542, case2) {
			istringstream in("ZhnqZlbTCiol .,YHsWlKfYf.,.Ug, .LPkReTwCoTUVAY.,Pv .BZRkvRZ,..uoeeEtwPLn.oLjdlYaolkctEM EUbsyHRPfHgtKXw s .a.HVZk. .JV ..TP,msuKHuIHETiPdNe, A,,.L,,.mbppWtkj.. KoURloeEO.  URJNwpFSj,FCfPqxH .Hvzk KzoZGPIRh .cluMByzNQCnrds.  lPKrEtWCOTUvAY...a,,UQq,.TP.IDNmLWyuBA ,ukTFWJtGaYpv,.kOurLOeEO,,.pwBwtcIPBNjQaX,  Gzc .FY.ug,,sZzrQnZnoKAyvOT,.ynHN, .iht,hVZK.  SzzrqNznoKAYvoT.. a. GzC. ,uoEEETWpLn,,jmozwuAaMnTCBx . URjNwPfsJ,BDQxCSWMkebF,, lPkretWcotUVaY . UOeeetWpln  pWBwtcIpBnjqAx CluMbYZNqcnrDS,,,MBPPwTkj pujlNV,..BzrkvrZ,.NJ,,,OTjJ zbWP..FaIPSfd  ,VbAXOCeUuc ..PAoOyvSlYxjcwA uQQ cmmhLELseIBMmj  ZBWP,.ZPVxAgLRHmPmn  lPKrETwCOtuvAY jV rrfG,URJNWpfSJ.  xDKcrUHgv EhKqG .MsUKhuIHeTipdnE ,,kZOzgPIRH vgWC.,EhKqg zhNqzLbTCioL.,uktfWJTGaYPV. ,fcfPQXh..Q.BDQXcSWMkeBF..fY,nJ,,PBODNCHgtV,, TOrAepgX   koURlOeEo.,.PwBWTcIPbnJQax,,OSfU Jv,,ENTiYAJD.zPvXagLrHmpmN.oTJJ.,.EbnaotBLnRhwdX. ,UkTfWjtgaypv ..EbNAOtBLNRhwdx pAOOYVsLYXjCWA SZZRQnZNOkayVot.,.EbnaOtblNrHwdx  ,KzoZgpirH, LPkretwcotuvAY..cRyi,.Rrfg.cmM");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("a:4\n"
			          "bdqxcswmkebf:2\n"
			          "bzrkvrz:2\n"
			          "clumbyznqcnrds:2\n"
			          "cmm:1\n"
			          "cmmhlelseibmmj:1\n"
			          "cryi:1\n"
			          "ebnaotblnrhwdx:3\n"
			          "ehkqg:2\n"
			          "entiyajd:1\n"
			          "eubsyhrpfhgtkxw:1\n"
			          "faipsfd:1\n"
			          "fcfpqxh:2\n"
			          "fy:2\n"
			          "gzc:2\n"
			          "hvzk:3\n"
			          "idnmlwyuba:1\n"
			          "iht:1\n"
			          "jmozwuaamntcbx:1\n"
			          "jv:3\n"
			          "kourloeeo:3\n"
			          "kzozgpirh:3\n"
			          "l:1\n"
			          "lpkretwcotuvay:5\n"
			          "mbppwtkj:2\n"
			          "msukhuihetipdne:2\n"
			          "nj:2\n"
			          "oljdlyaolkctem:1\n"
			          "osfu:1\n"
			          "otjj:2\n"
			          "paooyvslyxjcwa:2\n"
			          "pbodnchgtv:1\n"
			          "pujlnv:1\n"
			          "pv:1\n"
			          "pwbwtcipbnjqax:3\n"
			          "q:1\n"
			          "rrfg:2\n"
			          "s:1\n"
			          "szzrqnznokayvot:3\n"
			          "toraepgx:1\n"
			          "tp:2\n"
			          "ug:2\n"
			          "uktfwjtgaypv:3\n"
			          "uoeeetwpln:3\n"
			          "uqq:2\n"
			          "urjnwpfsj:3\n"
			          "vbaxoceuuc:1\n"
			          "vgwc:1\n"
			          "xdkcruhgv:1\n"
			          "yhswlkfyf:1\n"
			          "ynhn:1\n"
			          "zbwp:2\n"
			          "zhnqzlbtciol:2\n"
			          "zpvxaglrhmpmn:2\n",
			          ans);
		}
	}// namespace acwing3581

	/**
	 * @brief 785. 快速排序
	 */
	namespace acwing785_408 {
		TEST(acwing785_408, case1) {
			istringstream in("5\n"
			                 "3 1 2 4 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 2 3 4 5 ",
			          ans);
		}

		TEST(acwing785_408, case2) {
			istringstream in("30\n"
			                 "128 294 133 295 175 8 232 248 241 164 11 60 238 133 291 116 6 67 98 67 196 260 181 160 83 160 90 153 233 216");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("6 8 11 60 67 67 83 90 98 116 128 133 133 153 160 160 164 175 181 196 216 232 233 238 241 248 260 291 294 295 ",
			          ans);
		}
	}// namespace acwing785_408

	/**
	 * @brief 3504. 字符串转换整数
	 */
	namespace acwing3504 {
		TEST(acwing3504, case1) {
			istringstream in("2016");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2016",
			          ans);
		}

		TEST(acwing3504, case2) {
			istringstream in("o627CSo1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("627",
			          ans);
		}

		TEST(acwing3504, case3) {
			istringstream in("123456789123abc");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("-1",
			          ans);
		}

		TEST(acwing3504, case4) {
			istringstream in("abc");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("-1",
			          ans);
		}
	}// namespace acwing3504

	/**
	 * @brief 1603. 整数集合划分
	 */
	namespace acwing1603 {
		TEST(acwing1603, case1) {
			istringstream in("10\n"
			                 "23 8 10 99 46 2333 46 1 666 555");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0 3611",
			          ans);
		}

		TEST(acwing1603, case2) {
			istringstream in("13\n"
			                 "110 79 218 69 3721 100 29 135 2 6 13 5188 85");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("1 9359",
			          ans);
		}
	}// namespace acwing1603

	/**
	 * @brief 3527. 旋转矩阵
	 */
	namespace acwing3527 {
		TEST(acwing3527, case1) {
			istringstream in("3\n"
			                 "1 2 3\n"
			                 "4 5 6\n"
			                 "7 8 9\n"
			                 "7 4 1\n"
			                 "8 5 2\n"
			                 "9 6 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("90",
			          ans);
		}

		TEST(acwing3527, case2) {
			istringstream in("6\n"
			                 "5 2 5 1 2 6\n"
			                 "6 4 5 2 3 4\n"
			                 "2 4 3 4 1 1\n"
			                 "5 4 1 4 6 6\n"
			                 "5 4 3 4 1 5\n"
			                 "5 5 1 1 2 5\n"
			                 "6 4 1 6 5 5\n"
			                 "2 3 1 6 1 2\n"
			                 "1 2 4 4 4 1\n"
			                 "5 5 3 1 3 1\n"
			                 "2 4 4 4 5 4\n"
			                 "5 6 2 5 5 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("-1",
			          ans);
		}
	}// namespace acwing3527

	/**
     * @brief 3534. 矩阵幂
     */
	namespace acwing3534 {
		TEST(acwing3534, case1) {
			istringstream in("2 2\n"
			                 "9 8\n"
			                 "9 3");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("153 96 \n"
			          "108 81 \n",
			          ans);
		}
	}// namespace acwing3534

	/**
	 * @brief 3535. C翻转
	 */
	namespace acwing3535 {
		TEST(acwing3535, case1) {
			istringstream in("1 2 3 4 5\n"
			                 "6 7 8 9 10\n"
			                 "11 12 13 14 15\n"
			                 "16 17 18 19 20\n"
			                 "21 22 23 24 25\n"
			                 "1 3 1 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("11 6 1 4 5 \n"
			          "12 7 2 9 10 \n"
			          "13 8 3 14 15 \n"
			          "16 17 18 19 20 \n"
			          "21 22 23 24 25 \n",
			          ans);
		}

		TEST(acwing3535, case2) {
			istringstream in("19 5 7 16 12\n"
			                 "17 9 6 9 11\n"
			                 "9 19 14 10 8\n"
			                 "11 12 20 2 13\n"
			                 "16 10 7 2 10\n"
			                 "1 2 3 4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("19 5 7 16 12 \n"
			          "17 9 6 9 11 \n"
			          "9 19 14 2 10 \n"
			          "11 12 20 13 8 \n"
			          "16 10 7 2 10 \n",
			          ans);
		}
	}// namespace acwing3535

	/**
	 * @brief 3874. 三元组的最小距离
	 */
	namespace acwing3874 {
		TEST(acwing3874, case2) {
			istringstream in("3 4 5\n"
			                 "-1 0 9\n"
			                 "-25 -10 10 11\n"
			                 "2 9 17 30 41");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("2",
			          ans);
		}
	}// namespace acwing3874

	/**
	 * @brief 52. 数组中出现次数超过一半的数字
	 */
	namespace acwing52 {
		TEST(acwing52, case1) {
			vector<int> input = {1, 2, 1, 1, 3};
			moreThanHalfNum_Solution(input);
			ASSERT_EQ(moreThanHalfNum_Solution(input), 1);
		}
	}// namespace acwing52

	/**
	 * @brief 3392. 递推数列
	 */
	namespace acwing3392 {
		TEST(acwing3392, case1) {
			istringstream in("20 1 1 14 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("8359", ans);
		}

		TEST(acwing3392, case2) {
			istringstream in("1 10000 1 1 1");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("0", ans);
		}
	}// namespace acwing3392

	/**
	 * @brief 3433. 吃糖果
	 */
	namespace acwing3433 {
		TEST(acwing3392, case2) {
			istringstream in("4");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("5", ans);
		}
	}// namespace acwing3433

	/**
	 * @brief 3441. 重复者
	 */
	namespace acwing3441 {
		TEST(acwing3441, case1) {
			istringstream in("3\n"
			                 "# #\n"
			                 " # \n"
			                 "# #\n"
			                 "1\n"
			                 "3\n"
			                 "# #\n"
			                 " # \n"
			                 "# #\n"
			                 "3\n"
			                 "4\n"
			                 " OO \n"
			                 "O  O\n"
			                 "O  O\n"
			                 " OO \n"
			                 "2\n"
			                 "0");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("# #\n"
			          " # \n"
			          "# #\n"
			          "# #   # #         # #   # #\n"
			          " #     #           #     # \n"
			          "# #   # #         # #   # #\n"
			          "   # #               # #   \n"
			          "    #                 #    \n"
			          "   # #               # #   \n"
			          "# #   # #         # #   # #\n"
			          " #     #           #     # \n"
			          "# #   # #         # #   # #\n"
			          "         # #   # #         \n"
			          "          #     #          \n"
			          "         # #   # #         \n"
			          "            # #            \n"
			          "             #             \n"
			          "            # #            \n"
			          "         # #   # #         \n"
			          "          #     #          \n"
			          "         # #   # #         \n"
			          "# #   # #         # #   # #\n"
			          " #     #           #     # \n"
			          "# #   # #         # #   # #\n"
			          "   # #               # #   \n"
			          "    #                 #    \n"
			          "   # #               # #   \n"
			          "# #   # #         # #   # #\n"
			          " #     #           #     # \n"
			          "# #   # #         # #   # #\n"
			          "     OO  OO     \n"
			          "    O  OO  O    \n"
			          "    O  OO  O    \n"
			          "     OO  OO     \n"
			          " OO          OO \n"
			          "O  O        O  O\n"
			          "O  O        O  O\n"
			          " OO          OO \n"
			          " OO          OO \n"
			          "O  O        O  O\n"
			          "O  O        O  O\n"
			          " OO          OO \n"
			          "     OO  OO     \n"
			          "    O  OO  O    \n"
			          "    O  OO  O    \n"
			          "     OO  OO     \n",
			          ans);
		}
	}// namespace acwing3441

	/**
	 * @brief 2. 01背包问题
	 */
	namespace acwing2 {
		TEST(acwing2, case1) {
			istringstream in("4 5\n"
			                 "1 2\n"
			                 "2 4\n"
			                 "3 4\n"
			                 "4 5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("8", ans);
		}
	}// namespace acwing2

	/**
	 * @brief 3445. 点菜问题
	 */
	namespace acwing3445 {
		TEST(acwing3445, case1) {
			istringstream in("90 4\n"
			                 "20 25\n"
			                 "30 20\n"
			                 "40 50\n"
			                 "10 18");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("95", ans);
		}

		TEST(acwing3445, case2) {
			istringstream in("300 20\n"
			                 "19 24\n"
			                 "26 3\n"
			                 "2 5\n"
			                 "17 8\n"
			                 "13 17\n"
			                 "10 9\n"
			                 "19 9\n"
			                 "30 4\n"
			                 "23 24\n"
			                 "9 9\n"
			                 "5 22\n"
			                 "10 15\n"
			                 "9 10\n"
			                 "15 29\n"
			                 "20 14\n"
			                 "8 12\n"
			                 "4 23\n"
			                 "24 22\n"
			                 "16 13\n"
			                 "5 26");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("298", ans);
		}
	}// namespace acwing3445

	/**
	 * @brief 3442. 神奇的口袋
	 */
	namespace acwing3442 {
		TEST(acwing3442, case1) {
			istringstream in("3\n"
			                 "20\n"
			                 "20\n"
			                 "20");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("3", ans);
		}

		TEST(acwing3442, case2) {
			istringstream in("20\n"
			                 "1\n"
			                 "2\n"
			                 "2\n"
			                 "5\n"
			                 "4\n"
			                 "5\n"
			                 "5\n"
			                 "2\n"
			                 "3\n"
			                 "5\n"
			                 "1\n"
			                 "4\n"
			                 "3\n"
			                 "5\n"
			                 "4\n"
			                 "3\n"
			                 "3\n"
			                 "2\n"
			                 "3\n"
			                 "5");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("37564", ans);
		}
	}// namespace acwing3442

	/**
	 * @brief 3382. 整数拆分
	 */
	namespace acwing3382 {
		TEST(acwing3382, case1) {
			istringstream in("7");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("6", ans);
		}
	}// namespace acwing3382

	/**
	 * @brief 3389. N 的阶乘
	 */
	namespace acwing3389 {
		TEST(acwing3389, case1) {
			istringstream in("4\n"
			                 "5\n"
			                 "15");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("24\n"
			          "120\n"
			          "1307674368000\n",
			          ans);
		}
	}// namespace acwing3389

	/**
	 * @brief 3448. 基本算术
	 */
	namespace acwing3448 {
		TEST(acwing3448, case1) {
			istringstream in("123 456\n"
			                 "555 555\n"
			                 "123 594\n"
			                 "0 0");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("No carry operation.\n"
			          "3 carry operations.\n"
			          "1 carry operation.\n",
			          ans);
		}

		TEST(acwing3448, case2) {
			istringstream in("123 456\n"
			                 "555 555\n"
			                 "123 594\n"
			                 "99999 1\n"
			                 "167 33\n"
			                 "5 55\n"
			                 "0 1\n"
			                 "1654 69565\n"
			                 "999999999 999999999\n"
			                 "0 0");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("No carry operation.\n"
			          "3 carry operations.\n"
			          "1 carry operation.\n"
			          "5 carry operations.\n"
			          "2 carry operations.\n"
			          "1 carry operation.\n"
			          "No carry operation.\n"
			          "3 carry operations.\n"
			          "9 carry operations.\n",
			          ans);
		}
	}// namespace acwing3448

	/**
	 * @brief 3453. 整数查询
	 */
	namespace acwing3453 {
		TEST(acwing3448, case1) {
			istringstream in("123456789012345678901234567890\n"
			                 "123456789012345678901234567890\n"
			                 "123456789012345678901234567890\n"
			                 "0");
			auto out = ostringstream();
			main(in, out);
			const auto ans = out.str();
			ASSERT_EQ("370370367037037036703703703670", ans);
		}
	}// namespace acwing3453
}// namespace acwing