// Author: Leila kalantari
2 // Assignment: Program_03
3 // Date: 3 Decebmer 2019
4 // Title: Program 3 - BigNum
5 // Semester: Spring 2018
6 // Course: CMPS 1063
7 //
8 // Files: BigNum.hpp,
9 // doubly_linked.hpp,
10 // input_data.txt
11 // output.num
12 // Description:
13 // Addition and Subtraction of two big numbers
14 //
15
16
17
18
19 #include <string>
20 #include "DLList.hpp"
21
22 using namespace std;
23
24 class BigNum {
25 private:
26 DLList *BNum1;
27 DLList *BNum2;
28 public:
29 /**
30 * Create a BigNum with an empty list. No value yet.
31 */
32 BigNum(){
33 BNum1 = new DLList();
34 BNum2 = new DLList();
35 }
36
37 /**
38 * Add some other BigNum to this BigNum and return the
39 * result (as a BigNum). The original two BigNums should be unaffected.
40 */
41 DLList* Add(DLList *bnum1, DLList *bnum2,ofstream& out){
42 BNum1 = bnum1;
43 BNum2 = bnum2;
44
45
46
47 int num1=0;
48 int num2=0;
49 int carry=0;
50 int sum=0;
51
52
53 DLList* Result = new DLList();
54
55
56 while(!BNum1->Empty()){
57 num1 = BNum1->Delete();
58 num2 = BNum2->Delete();
59 sum = num1 + num2 + carry;
60 carry = sum / 10;
61 sum = sum % 10;
62 out<<num1<<" "<<num2<<" "<<sum<<" "<<carry<<endl;
63 Result->InsertFront(sum);
64 }
65 // handle carry + rest of nums
66 return Result;
67 }
68
69 /* **
70 * Sub
71 *
72 * Description:
73 * Subs an "other" doubly linked list to "this" list
74 *
75 * Params:
76 * BigNum other : two "*bnum1 and *bnum2" list
77 *
78 * Returns:
79 * BigNum : a doubley linked list with subtraction results
80 */
81
82 DLList* Sub(DLList *bnum1, DLList *bnum2,ofstream& out){
83 BNum1 = bnum1;
84 BNum2 = bnum2;
85
86 int num1=0;
87 int num2=0;
88 int carry=0;
89 int sub=0;
90
91
92 if(BNum1->Bigger(*BNum2)){
93 out<<"BNum1 bigger."<<endl;// BNum1 bigger
94
95 while(!BNum1->Empty()){
96 num1 = BNum1->Delete();
97 num2 = BNum2->Delete();
98 num1=num1-carry;
99 carry=0;
100 if(num1>=num2)
101 sub=num1-num2;
102 else{
103 num1=num1+10;
104 sub=num1-num2;
105 carry=1;
106 }
107 out<<num1<<" "<<num2<<" "<<sub<<" "<<carry<<endl;
108 out<<sub;
109
110 }
111 }else{
112 out<<"BNum2 bigger."<<endl;//BNum2 bigger
113
114 while(!BNum1->Empty()){
115 num1 = BNum1->Delete();
116 num2 = BNum2->Delete();
117 num2=num2-carry;
118 carry=0;
119 if(num2>=num1)
120 sub=num2-num1;
121 else{
122 num2=num2+10;
123 sub=num2-num1;
124 carry=1;
125 }
126 out<<num1<<" "<<num2<<" "<<sub<<" "<<carry<<endl;
127
128 }
129
130 }
131
132 return bnum1;
133
134 }
135
136 };
