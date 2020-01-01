// BARTU BOZKURT 2017280013
#include<string>
#include <iostream>
#include <fstream>
#include<vector>

using namespace std;

int main() {
	string st;
	vector<string> anahtar(4);
    int puan =0;
    int ogrSayi=0;
    int puanp=0;

    ifstream satirsay("input.txt");
	string str,q,r;
	
    while(getline(satirsay,r))
    	  ogrSayi++;

    satirsay.close();
    ogrSayi = ogrSayi -2;
	
	
    vector<int> ogrPuanlar (ogrSayi);
    ifstream dosya1("input.txt");
    
	int kacSoru = 0;
	int i=0,j=0;
    while(getline(dosya1,st)){
    	puan = 0;
    	int say = 0;
    	if(i == 0){
    		kacSoru = stoi(st);
    		i++;
		}
		if(j==1){
			str =st;
			anahtar.resize(kacSoru);
			int i1 =0;
			for(int j1 = 0; j1 < st.length(); j1++){
				q =str.substr(j1,1);
				if(q != ","){
					anahtar[i1] = q;
					i1++;
				}
			}
			j++;
		}
		if(i==1 && j > 2){
			str = st;
			for(int i2 = 10; i2 < str.length();i2++){
				q = str.substr(i2,1);
				if(q != ","){
					if(q == anahtar[say])
							 puan += 4;
				 	else if(q == " ")
					 	 puan += 0;
					else
						puan -= 1;

					say++;
				}
			}
			ogrPuanlar[puanp] = puan;
			puan = 0;
			puanp++;
		}
		j++;
	}

 	int temp = 0,sum=0;
    for (int j3= 0;  j3 < ogrSayi; j3++) {
    	sum += ogrPuanlar[j3];
    	for(int i3 = 0; i3 < ogrSayi; i3++){
        		if (ogrPuanlar[i3] > ogrPuanlar[j3]) {
					temp = ogrPuanlar[j3];
					ogrPuanlar[j3] = ogrPuanlar[i3];
					ogrPuanlar[i3] = temp;
        }
   	  }
    }
	int MAX = 0;
	int MIN = 0;
	int Ortalama = 0;
	int Aciklik;

	Ortalama = sum / ogrSayi;
	MAX = ogrPuanlar[ogrSayi -1];
	MIN = ogrPuanlar[0];
    Aciklik = MAX - MIN;

	for (int i4 = 0; i4 < ogrSayi; i4++)
		cout << ogrPuanlar[i4] << ",";

	dosya1.close();

	ofstream dosya2("output.txt");
	
	int m,m1;

	dosya2 << "EN YUKSEK NOT = " << MAX << endl;
	dosya2 << "EN DUSUK NOT = " << MIN << endl;
	dosya2 << "ORTALAMA = " << Ortalama  << endl;
	dosya2 << "ACIKLIK = " << Aciklik << endl;
	if(ogrSayi % 2 == 0){
		m = ogrPuanlar[ogrSayi / 2 - 1];
		m1 = ogrPuanlar[ogrSayi /2];
		dosya2  << "MEDYAN = " << m << " " << m1 << endl;
	}
	else{
		m =ogrPuanlar[ogrSayi / 2];
		dosya2 << "MEDYAN = " << m << endl;
	}

	dosya2.close();
    return 0;
	//https://www.youtube.com/watch?v=7eLVEVhG-9Y
	//https://www.youtube.com/watch?v=Cq1h1KPoGBU
	//https://www.youtube.com/watch?v=vR1fI7vkFsQ
	//https://www.geeksforgeeks.org/getline-string-c/
	//https://www.geeksforgeeks.org/median/
}

