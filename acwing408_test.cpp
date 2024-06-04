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
}// namespace acwing