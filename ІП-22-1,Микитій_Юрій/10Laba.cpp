

   #include <locale>
   #include <iostream>
   #include <vector>
   using namespace std;
   
   // ������ ����� ������
   int search(string s, string p) {
       int n = s.size();
       int m = p.size();
       for (int i = 0; i <= n - m; i++) {
           int j;
           for (j = 0; j < m; j++)
               if (s[i + j] != p[j])
                   break;
           if (j == m)
               return i;
       }
       return -1;
   }
   
   // �������� �����, ����� � ����� (���)
   vector<int> computeprefix(string p) {
       int m = p.size();
       vector<int> longestprefix(m);
       for (int i = 1, k = 0; i < m; i++) {
           while (k > 0 && p[k] != p[i])
               k = longestprefix[k - 1];
           if (p[k] == p[i])
               k++;
           longestprefix[i] = k;
       }
       return longestprefix;
   }
   
   int kmp(string s, string p) {
       int n = s.size();
       int m = p.size();
       vector<int> longestprefix = computeprefix(p);
       for (int i = 0, k = 0; i < n; i++) {
           while (k > 0 && p[k] != s[i])
               k = longestprefix[k - 1];
           if (p[k] == s[i])
               k++;
           if (k == m)
               return i - m + 1;
       }
       return -1;
   }
   
   int main() {
       setlocale(LC_CTYPE, "ukr");
       // ��� ��� ���
       string s = "hellhellow";
       string p = "hellow";
       int index = search(s, p);
       if (index != -1) {
           cout << "������ ����� ������: ����� �������� � �����i �� �����i� " << index << endl;
       }
       else {
           cout << "������ ����� ������: ����� �� �������� � �����i" << endl;
       }
   
       index = kmp(s, p);
       if (index != -1) {
           cout << "�������� �����, ���i�� i ����� (���): ����� �������� � �����i �� �����i� " << index << endl;
       }
       else {
           cout << "�������� �����, ����� i ����� (���): ����� �� �������� � �����i" << endl;
       }
   
       return 0;
   }
