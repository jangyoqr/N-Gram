#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include <iomanip>
#include<sstream>
#include<vector>
using namespace std;
long long unitotal = 0;//모든 유니그램 빈도수의 합이다.
long long bitotal = 0;//모든 바이그램 단어의 개수이다.
long long tritotal = 0;//모든 트라이그램 단어의 개수이다.
long long hugeBi = 0;//큰 바이그램의 경우에서, 검색한 데이터의 빈도수다
long long hugeTri = 0;//큰 트라이그램의 경우에서, 검색한 데이터의 빈도수다
vector<pair<string, int>> v;//유니그램의 경우 벡터에 읽은 데이터를 벡터에 저장을한다.
vector<pair<string, int>> v2;// 작은 크기의 바이그램의 경우 벡터에 읽은 데이터를 벡터에 저장을한다
vector<pair<string, int>> v3;// 작은 크기의 트라이그램의 경우 벡터에 읽은 데이터를 벡터에 저장을한다

//unigram 파일의 크기과 상관 없이 사용가능하다.
void uniFileRead(const char* _path) {
	FILE * pFile = fopen(_path, "rb");

	//read size of file
	fseek(pFile, 0, SEEK_END);
	long lSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	string a(buff);
	free(buff);
	stringstream iss;
	iss.str(a);
	int num;
	string data;
	unitotal = 0;
	while (iss>>num>>data)
	{
	unitotal += num;//모든 유니그램의 빈도수를 더해준다.
	pair<string, int> p = make_pair(data, num);
	v.push_back(p);
	}

	sort(v.begin(), v.end());//문장의 순서를 기준으로 정렬 만약 동일한 순서면 횟수에 따라 정렬
	fclose(pFile);
	a.clear();
	iss.clear();
}
//작은 파일 크기의 bigram을 읽을 때 사용한다.
void biFileRead(const char* _path) {
	FILE * pFile = fopen(_path, "rb");

	//read size of file
	fseek(pFile, 0, SEEK_END);
	long lSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	string a(buff);
	free(buff);
	stringstream iss;
	iss.str(a);
	
	int num;
	string data;

	bitotal = 0;
	while (iss >> num >> data)
	{

		bitotal += 1;
		pair<string, int> p = make_pair(data, num);
		v2.push_back(p);
	}
	sort(v2.begin(), v2.end());//문장의 순서를 기준으로 정렬 만약 동일한 순서면 횟수에 따라 정렬
	fclose(pFile);
	a.clear();
	iss.clear();
}
//작은 파일 크기의 bigram을 읽을 때 사용한다.
void hugeBiFileRead(const char* _path, string check) {
	FILE * pFile = fopen(_path, "rb");

	//read size of file
	fseek(pFile, 0, SEEK_END);
	long lSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}
	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	string a(buff);
	free(buff);
	stringstream iss;
	iss.str(a);
	a.clear();
	int num;
	string data;
	while (iss >> num >> data)
	{
		bitotal += 1;
		if (data == check) {
			hugeBi = num;
		}
	}

	fclose(pFile);
	a.clear();
	iss.clear();
}
//작은 파일 크기의trigram을 읽을 때 사용한다.
void triFileRead(const char* _path) {
	FILE * pFile = fopen(_path, "rb");

	//read size of file
	fseek(pFile, 0, SEEK_END);
	long lSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	string a(buff);
	free(buff);
	stringstream iss;
	iss.str(a);
	a.clear();
	int num;
	string data;

	tritotal = 0;
	while (iss >> num >> data)
	{
		tritotal += num;
		pair<string, int> p = make_pair(data, num);
		v3.push_back(p);
	}

	sort(v3.begin(), v3.end());//문장의 순서를 기준으로 정렬 만약 동일한 순서면 횟수에 따라 정렬
	fclose(pFile);
	a.clear();
	iss.clear();
}
//큰 파일 크기의 trigram을 읽을 때 사용한다.
void hugeTriFileRead(const char* _path, string check) {
	FILE * pFile = fopen(_path, "rb");

	//read size of file
	fseek(pFile, 0, SEEK_END);
	long lSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	string a(buff);
	free(buff);
	stringstream iss;
	iss.str(a);
	a.clear();
	int num;
	string data;
	while (iss >> num >> data)
	{
		//bitotal += num;
		tritotal += 1;
		if (data == check) {
			hugeTri = num;
		}
	}

	fclose(pFile);
	a.clear();
	iss.clear();
}
//입력파일을 바이그램으로 만들어준다.
void makeBigram(const char* _path, const char* _pathResult) {
	FILE * pFile = fopen(_path, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	//read size of file
	fseek(pFile, 0, SEEK_END);// 파일 포인터를 파일의 끝으로 이동
	long lSize = ftell(pFile);// 파일 시작부터 맨 끝까지의 거리를 return
	fseek(pFile, 0, SEEK_SET);// 파일 포인터를 파일의 처음으로 이동

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	buff[totnum] = NULL;
	string a(buff);
	fclose(pFile);
	stringstream iss;
	stringstream iss2;
	iss.str(a);
	int num;
	string data; string data2; string data3;
	int check;
	int i = 0;
	string temp;
	while (getline(iss, data, '\n'))
	{
		iss2.str(data);
		i = 0;
		while (1)
		{
			
			i++;
			if (i == 1)
			{
				iss2 >> data2;
				temp += (data2+"\rn");
				if (!(iss2 >> data3))break;
			}
			else if (i % 2 == 0)
			{
	
				temp += (data2 + data3 + "\rn");
				if (!(iss2 >> data2))
				{
					temp += (data3 + "\rn");
					break;
				}
			}
			else {
				temp += (data3 + data2 + "\r\n");
				if (!(iss2>>data3)) {
					temp += (data2 + "\r\n");
					break;
				}
			}
		}
		myfile.write(temp.c_str(), temp.size());
		iss2.clear();
		temp.clear();
	}
	
	myfile.close();

}
//입력 파일을 트라이그램으로 만들어준다.
void makeTrigram(const char* _path, const char* _pathResult) {
	FILE * pFile = fopen(_path, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	//read size of file
	fseek(pFile, 0, SEEK_END);// 파일 포인터를 파일의 끝으로 이동
	long lSize = ftell(pFile);// 파일 시작부터 맨 끝까지의 거리를 return
	fseek(pFile, 0, SEEK_SET);// 파일 포인터를 파일의 처음으로 이동

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	buff[totnum] = NULL;
	string a(buff);
	fclose(pFile);
	
	stringstream iss;
	stringstream iss2;

	iss.str(a);

	//a.clear();
	int num;
	string data;
	string data1;
	string data2;
	string data3;
	int check;
	int i = 0;
	string temp;
	
	while (getline(iss, data, '\n'))
	{
		iss2.str(data);
		i = 1;
		while (1)
		{
			if (i == 1)
			{   
				i++;
				iss2 >> data3;
				temp += (data3); //시작 $$data이다 이는 3개의 단어가 합쳐진것이다
				if (!(iss2 >> data2)) break;
				else if (!(iss2 >> data1)) {
					temp += (data3 + data2+"\r\n"); //두번째 $data3data2  이는 3개의 단어가 합쳐진것이다
					temp += (data3+ data2+ "\r\n");//문장에 단어가 2개만 있기때문에 마지막으로
					temp += (data2+ "\r\n");//문장에 단어가 2개만 있기때문에 마지막으로
					break;
				}
				else {
					temp += (data3 + data2 + "\r\n");//라인에 단어가 3개 이상인 상황이다.
					temp += ( data3 + data2+data1 + "\r\n");//dat3 data2 data1는 각각 한 단어 씩이 할당 된다.
				}
			}
			else 
			{
				data3 = data2;
				data2 = data1;
				//단어들을 한칸씩 땡겨준다. data3(1),data2(2),data1(3)이라면, data3(2)data2(3)data1(data 얻어 오기전) 이다. 					
				if ((iss2 >> data1))//data1에 단어를 얻어온다. 따라서 그결과 data3(2),data2(3),data4(4)와 같이 단어가 할당된다.
				{
					temp += (data3 + data2 + data1 + "\r\n");
				}
				else 
				{//한 라인에 더이상 단어가 없는 경우 실행이 된다. 하지만 data3 data2에는 단어가 있음으로 이는 트라이그램으로 만들어 준다.
					temp += (data3+data2+ "\r\n");
					temp += (data2 + "\r\n");
					break;
				}
			}
		}

		myfile.write(temp.c_str(), temp.size());
		iss2.clear();
		temp.clear();
		
	}
	iss.clear();
	iss2.clear();
	a.clear();
	myfile.close();
	

}
//유니그램에서 원하는 단어의 빈도 수를 찾을 때 사용한다.
//작은 크기의 바이그램에서 원하는 단어의 빈도 수를 찾을 때 사용한다.
int uniFind(string sentence)
{
	long long left = 0;
	long long right = v.size();
	long long mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (sentence > v[mid].first) {
			left = mid + 1;
		}
		else if (sentence < v[mid].first) {
			right = mid;
		}
		else {
			return v[mid].second;
		}
	}
	return false;
}
int biFind(string sentence)
{
	long long left = 0;
	long long right = v2.size();
	long long mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (sentence > v2[mid].first) {
			left = mid + 1;
		}
		else if (sentence < v2[mid].first) {
			right = mid;
		}
		else {
			return v2[mid].second;
		}
	}
	return false;

}
//작은 크기의 트라이그램에서 원하는 단어의 빈도 수를 찾을 때 사용한다.
int triFind(string sentence)
{
	long long left = 0;
	long long right = v3.size();
	long long mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (sentence > v3[mid].first) {
			left = mid + 1;
		}
		else if (sentence < v3[mid].first) {
			right = mid;
		}
		else {
			return v3[mid].second;
		}
	}
	return false;

}
//큰 사이즈의 바이그램 확률을 구할 때 사용한다.
void hugeBigram(const char* _unigram, const char* _bigram)
{
	
	string temp;
	string temp2;
	int prob;

	cout << "바이그램을 입력하세요: "; //입력시 정치 투쟁 과 같이 space값을 준다.
	cin >> temp >> temp2;
	uniFileRead(_unigram);
	cout << "유니그램 읽기 완료" << "\n";
	prob = uniFind(temp);
	v.clear();
	temp += temp2;
	v.clear();
	hugeBiFileRead(_bigram,temp2);
	cout << "바이그램 읽기 완료" << "\n";
	cout << temp << " 확률은: " << (double)(hugeBi + 1) / (prob + bitotal) << "\n";
	
}
//큰 사이즈의 트라이그램 확률을 구할 때 사용한다.
void hugeTrigram(const char* _bigram, const char* _trigram)
{
	string temp;
	string temp2;
	string temp3;

	cout << "트라이그램을 입력하세요: "; //입력시 언론 장악 문건 과 같이 space값을 준다.
	cin >> temp >> temp2>>temp3;
	v.clear();
	temp += temp2;
	hugeBiFileRead(_bigram, temp);
	cout << "바이그램 읽기 완료" << "\n";
	temp += temp3;
	hugeTriFileRead(_trigram, temp);
	cout << "트라이그램 읽기 완료" << "\n";
	cout << temp << " 확률은: " << (double)(hugeTri + 1) / (hugeBi + tritotal) << "\n";
}
//바이그램을 확률을 구할 때 사용한다.
void bigram()
{
	string temp;
	string temp2;

	stringstream ss;
	int prob;
	cout << "바이그램을 입력하세요: ";
	cin >> temp>>temp2;
	
	prob = uniFind(temp);
	temp += temp2;
	cout << temp <<" 확률은: " << (double) (biFind(temp)+1)/ (prob+v.size());
}
//작은 사이즈의 유니그램 확률을 구할 때 사용한다.
void unigramSentence(const char* _path, const char* _targetPath, const char* _pathResult)
{
	uniFileRead(_path);//유니그램을 읽는다.
	cout << "유니그램 읽기 완료" << endl;
	FILE * pFile = fopen(_targetPath, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	fseek(pFile, 0, SEEK_END);// 파일 포인터를 파일의 끝으로 이동
	long lSize = ftell(pFile);// 파일 시작부터 맨 끝까지의 거리를 return
	fseek(pFile, 0, SEEK_SET);// 파일 포인터를 파일의 처음으로 이동

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	buff[totnum] = NULL;
	string a(buff);
	fclose(pFile);
	stringstream iss;
	stringstream iss2;
	iss.str(a);
	int num;
	string data; string data2; string data3;
	stringstream stream;
	double total = 1;
	double temp = 1;
	string temp2;
	while (getline(iss, data, '\n'))
	{
		iss2.str(data);
		while (iss2 >> data2)
		{
			num = uniFind(data2);
			temp = (double)(num + 1) / (v.size() + unitotal);
			total *= temp;
		}
		myfile << total;
		temp2 += " ";
		temp2 += (data+"\r\n");
		myfile.write(temp2.c_str(), temp2.size());
		iss2.clear();
		stream.clear();
		temp2.clear();
		total = 1;
	}
	cout << "유니그램 확률 분석 완료" << "\n\n";
	myfile.close();
	v.clear();

}
//작은 사이즈의 트라이그램 확률을 구할 때 사용한다.
void bigramSentence(const char* _unipath, const char* _bipath, const char* _targetPath, const char* _pathResult)
{
	uniFileRead(_unipath);//유니그램을 읽는다.
	cout << "유니그램 읽기 완료" << endl;
	biFileRead(_bipath);//바이그램을 읽는다.
	cout << "바이그램 읽기 완료" << endl;
	FILE * pFile = fopen(_targetPath, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	fseek(pFile, 0, SEEK_END);// 파일 포인터를 파일의 끝으로 이동
	long lSize = ftell(pFile);// 파일 시작부터 맨 끝까지의 거리를 return
	fseek(pFile, 0, SEEK_SET);// 파일 포인터를 파일의 처음으로 이동

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	buff[totnum] = NULL;
	string a(buff);
	fclose(pFile);
	stringstream iss;
	stringstream iss2;
	iss.str(a);
	int uni;
	int bi;
	string data; string data2; string data3;
	double total = 1;
	string temp;
	int temp3;
	int i = 0;
	while (getline(iss, data, '\n'))
	{
		iss2.str(data);
		iss2 >> data2;
		uni = uniFind(data2);
		bi = biFind(data2);
		total *= ((double)(bi + 1) / (uni + bitotal));
		while (1)
		{
			if (iss2 >> data3) {
				uni = uniFind(data2);
				bi = biFind(data2+data3);
				total *= ((double)(bi + 1) / (uni + bitotal));
				data2 = data3;
			}
			else {
				uni = uniFind(data2);
				bi = biFind(data2);
				total *= ((double)(bi + 1) / (uni + bitotal));
				break;
			}
		}
		myfile << total;
		temp += " ";
		data += "\r\n";
		temp += data;
		myfile.write(temp.c_str(), temp.size());
		iss2.clear();
		temp.clear();
		total = 1;
	}

	myfile.close();
	cout << "바이그램 확률 분석 완료" << "\n\n";
	v.clear();
	v2.clear();
}
void trigramSentence(const char* _bipath, const char* _tripath, const char* _targetPath, const char* _pathResult)
{
	biFileRead(_bipath);//바이그램을 읽눈다.
	cout << "바이그램 읽기 완료" << endl;
	triFileRead(_tripath);//트라이그램을 읽는다
	cout << "트라이그램 읽기 완료" << endl;
	FILE * pFile = fopen(_targetPath, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	fseek(pFile, 0, SEEK_END);// 파일 포인터를 파일의 끝으로 이동
	long lSize = ftell(pFile);// 파일 시작부터 맨 끝까지의 거리를 return
	fseek(pFile, 0, SEEK_SET);// 파일 포인터를 파일의 처음으로 이동

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	buff[totnum] = NULL;
	string a(buff);
	fclose(pFile);
	stringstream iss;
	stringstream iss2;
	iss.str(a);
	int tri;
	int bi;
	string data; string data2; string data3;
	string data4;
	double total = 1;
	string temp;
	int temp3;
	int i = 0;
	while (getline(iss, data, '\n'))
	{
		iss2.str(data);
		iss2 >> data2>>data3;
		bi = biFind(data2);
		tri = triFind(data2);
		total *= ((double)(tri + 1) / (bi + tritotal));
		bi = biFind(data2+data3);
		tri = triFind(data3);
		total *= ((double)(tri + 1) / (bi + tritotal));
		while (1)
		{
			if (iss2 >> data4) {
				bi = biFind(data2+data3);
				tri = triFind(data2 + data3+data4);
				total *= ((double)(tri + 1) / (bi + tritotal));
				data2 = data3;
				data3 = data4;
			}
			else {
				bi = biFind(data2+data3);
				tri = triFind(data3);
				total *= ((double)(tri + 1) / (bi + tritotal));
				bi = biFind(data3);
				tri = triFind(data3);
				total *= ((double)(tri + 1) / (bi + tritotal));
				break;
			}
		}
		myfile << total;
		temp += " ";
		data += "\r\n";
		temp += data;
		myfile.write(temp.c_str(), temp.size());
		iss2.clear();
		temp.clear();
		total = 1;
	}

	myfile.close();
	cout << "트라이그램 확률 분석 완료" << "\n\n";
	v2.clear();
	v3.clear();
}
void trigtam()
{

	string temp;
	string temp2;
	string temp3;
	stringstream ss;
	int prob;
	cout << "트라이그램을 입력하세요: ";
	cin >> temp>>temp2>>temp3;
	temp += temp2;
	prob = biFind(temp);
	temp += temp3;
	cout << temp << " 확률은: " << (double)(triFind(temp) + 1) / (prob + bitotal);
} 
void compareSentence(const char* _path1, const char* _path2)
{
	FILE * pFile = fopen(_path1, "rb");
	FILE * pFile2 = fopen(_path2, "rb");
	fstream myfile;
	

	fseek(pFile, 0, SEEK_END);// 파일 포인터를 파일의 끝으로 이동
	long lSize = ftell(pFile);// 파일 시작부터 맨 끝까지의 거리를 return
	fseek(pFile, 0, SEEK_SET);// 파일 포인터를 파일의 처음으로 이동

	char *buff = (char*)malloc(sizeof(char)*lSize);

	long long totnum = 0;
	long long curnum = 0;

	//read all big file
	while ((curnum = fread(&buff[totnum], sizeof(char), lSize - totnum, pFile)) > 0) {
		totnum += curnum;
	}

	if (totnum != lSize) {
		cout << "not read all file" << endl;
	}
	buff[totnum] = NULL;

	fseek(pFile2, 0, SEEK_END);// 파일 포인터를 파일의 끝으로 이동
	long lSize2 = ftell(pFile2);// 파일 시작부터 맨 끝까지의 거리를 return
	fseek(pFile2, 0, SEEK_SET);// 파일 포인터를 파일의 처음으로 이동

	char *buff2 = (char*)malloc(sizeof(char)*lSize2);

	long long totnum2 = 0;
	long long curnum2 = 0;

	//read all big file
	while ((curnum2 = fread(&buff2[totnum2], sizeof(char), lSize2 - totnum2, pFile2)) > 0) {
		totnum2 += curnum2;
	}

	if (totnum2 != lSize2) {
		cout << "not read all file" << endl;
	}
	buff2[totnum2] = NULL;
	string a(buff);
	string a2(buff2);
	fclose(pFile);
	fclose(pFile2);
	stringstream iss;
	stringstream iss2;
	stringstream iss3;
	stringstream iss4;
	iss.str(a);
	iss2.str(a2);
	string num1, num2;
	string temp1;
	string temp2;
	int count1 = 0;
	int count2 = 0;
	while (getline(iss, temp1, '\n') && getline(iss2, temp2, '\n'))
	{
		iss3.str(temp1);
		iss4.str(temp2);
		iss3 >> num1;
		iss4 >> num2;
		if (atof(num1.c_str()) > atof(num2.c_str())) count1++;
		else count2++;
	}
	
	cout << "testK가 더 높은 확률 가진 문장의 개수는 : " << count1 << endl;
	cout << "testN가 더 높은 확률 가진 문장의 개수는 : " << count2 << "\n\n";
}
 
int main()
{
	

	char * uniKfile = "C:/Users/jangy/Desktop/test/kresult1.txt";//유니그램 검색을 위한 파일.
	char * uniNfile = "C:/Users/jangy/Desktop/test/nresult1.txt";//유니그램 검색을 위한 파일.
	char * uniKresult = "C:/Users/jangy/Desktop/test/uniKresult.txt";
	char * uniNresult = "C:/Users/jangy/Desktop/test/uniNresult.txt";
	char * sourceK = "C:/Users/jangy/Desktop/test/bigramKSource.txt";//바이그램,트라이그램으로 만들려는 파일.
	char * sourceN = "C:/Users/jangy/Desktop/test/bigramNSource.txt";//바이그램,트라이그램으로 만들려는 파일.
	char * BigramK = "C:/Users/jangy/Desktop/test/BigramK.txt";//K 의 바이그램
	char * BigramN = "C:/Users/jangy/Desktop/test/BigramN.txt";//N 의 바이그램
	char * BigramKWord = "C:/Users/jangy/Desktop/test/BigramK2.txt";//K 의 바이그램 wordcount 결과
	char * BigramNWord = "C:/Users/jangy/Desktop/test/BigramN2.txt";//N의 바이그램 wordcount 결과
	char * BigramKResult = "C:/Users/jangy/Desktop/test/BigramKResult.txt";//K 의 바이그램 분석 문장결과
	char * BigramNResult = "C:/Users/jangy/Desktop/test/BigramNResult.txt";//N 의 바이그램 분석 문장결과 
	char * TrigramK = "C:/Users/jangy/Desktop/test/TrigramK.txt";//K의 트라이그램
	char * TrigramN = "C:/Users/jangy/Desktop/test/TrigramN.txt";//N의 트라이그램	
	char * TrigramKWord = "C:/Users/jangy/Desktop/test/TrigramK2.txt";//K 의 트라이그램 wordcount 결과
	char * TrigramNWord = "C:/Users/jangy/Desktop/test/TrigramN2.txt";//N의 바이그램 wordcount 결과
	char * TrigramKResult = "C:/Users/jangy/Desktop/test/TrigramKResult.txt";//K 의 트라이그램 분석 문장결과
	char * TrigramNResult = "C:/Users/jangy/Desktop/test/TrigramNResult.txt";//N 의 트라이그램 분석 문장결과

	
	cout << "바이그램 확률 비교" << endl;
	compareSentence(uniKresult, uniNresult);
	cout << "유니그램 확률 비교" << endl;
	compareSentence(BigramKResult, BigramNResult);
	cout << "트라이그램 확률 비교" << endl;
	compareSentence(TrigramKResult, TrigramNResult);
   

	//unigramSentence(uniNfile, sourceN, uniNresult);
	//bigramSentence(uniNresult, BigramNWord, sourceN, BigramNResult);
	//trigramSentence(TrigramNWord, TrigramNWord, sourceN, TrigramNResult);
	//unigramSentence(uniKfile, sourceK, uniKresult);
	//bigramSentence(uniKresult, BigramKWord, sourceK, BigramKResult);
	//trigramSentence(TrigramKWord, TrigramKWord, sourceK, TrigramKResult);
	//makeTrigram(sourceN, TrigramN);
	//makeTrigram(sourceK, TrigramK);
	 //makeBigram(sourceN, BigramN);
	//makeBigram(sourceN, BigramN);
	//makeTrigram(sourceK, trigramK);
	//makeTrigram(sourceN, trigramN);
/*	char * makebifile = "C:/Users/jangy/Desktop/tmp/biResult.txt";//바이그램으로 만들어질 파일
	char * bifile = "C:/Users/jangy/Desktop/tmp/midResult.txt";//바이그램 파일
	char * maketrifile = "C:/Users/jangy/Desktop/tmp/triResult.txt";//트라이그램으로 만들어질 파일
	char * trifile = "C:/Users/jangy/Desktop/tmp/lastResult.txt";//wordcount로 만든 트라이그램포함
	int check;
	int check2;
	cout << "1. 작은 텍스트 파일 분석 2. 큰 텍스트 파일 분석 3. 바이그램으로 파일 만들기 4.트라이그램 파일 만들기: ";
	cin >> check;
	if (check == 1) {
		cout << "1. 유니그램 분석 2. 바이그램 분석 3. 트라이 그램 분석: ";
		cin >> check2;
		if (check2 == 1) {
			uniFileRead(unifile);
			unigram();
		}
		else if (check2 == 2) {

			if (v.size() > 1) {
				biFileRead(bifile);
				bigram();
			}
			else {
				uniFileRead(unifile);
				cout << "유니그램 읽기 완료" << "\n";
				biFileRead(bifile);
				cout << "바이그램 읽기 완료" << "\n";
				bigram();
			}
		}
		else if (check2 == 3) {
			if (v2.size() > 1) triFileRead(trifile);
			else {
				biFileRead(bifile);
				cout << "바이그램 읽기 완료" << "\n";
				triFileRead(trifile);
				cout << "트라이그램 읽기 완료" << "\n";
				trigtam();
			}
		}
		else cout << "잘못된 입력입니다" << "n";
	}
	else if (check == 2) {
		cout << "1. 유니그램 분석 2. 바이그램 분석 3. 트라이 그램 분석: ";
		cin >> check2;
		if (check2 == 1) {
			uniFileRead(unifile);
			cout << "유니그램 읽기 완료" << "\n";
			unigram();
		}
		else if (check2 == 2) {
			hugeBigram(unifile, bifile);
		}
		else if (check2 == 3) {
			hugeTrigram(bifile, trifile);
		}
		else cout << "잘못된 입력입니다" << "n";
	}
	else if (check == 3) {
		makeBigram(source, makebifile);
	}
	else if (check == 4) {
		makeTrigram(source, maketrifile);
	}
	else cout << "잘못된 입력입니다." << "\n";
	*/
}