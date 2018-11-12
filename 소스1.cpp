#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include <iomanip>
#include<sstream>
#include<vector>
using namespace std;
long long unitotal = 0;//��� ���ϱ׷� �󵵼��� ���̴�.
long long bitotal = 0;//��� ���̱׷� �ܾ��� �����̴�.
long long tritotal = 0;//��� Ʈ���̱׷� �ܾ��� �����̴�.
long long hugeBi = 0;//ū ���̱׷��� ��쿡��, �˻��� �������� �󵵼���
long long hugeTri = 0;//ū Ʈ���̱׷��� ��쿡��, �˻��� �������� �󵵼���
vector<pair<string, int>> v;//���ϱ׷��� ��� ���Ϳ� ���� �����͸� ���Ϳ� �������Ѵ�.
vector<pair<string, int>> v2;// ���� ũ���� ���̱׷��� ��� ���Ϳ� ���� �����͸� ���Ϳ� �������Ѵ�
vector<pair<string, int>> v3;// ���� ũ���� Ʈ���̱׷��� ��� ���Ϳ� ���� �����͸� ���Ϳ� �������Ѵ�

//unigram ������ ũ��� ��� ���� ��밡���ϴ�.
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
	unitotal += num;//��� ���ϱ׷��� �󵵼��� �����ش�.
	pair<string, int> p = make_pair(data, num);
	v.push_back(p);
	}

	sort(v.begin(), v.end());//������ ������ �������� ���� ���� ������ ������ Ƚ���� ���� ����
	fclose(pFile);
	a.clear();
	iss.clear();
}
//���� ���� ũ���� bigram�� ���� �� ����Ѵ�.
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
	sort(v2.begin(), v2.end());//������ ������ �������� ���� ���� ������ ������ Ƚ���� ���� ����
	fclose(pFile);
	a.clear();
	iss.clear();
}
//���� ���� ũ���� bigram�� ���� �� ����Ѵ�.
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
//���� ���� ũ����trigram�� ���� �� ����Ѵ�.
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

	sort(v3.begin(), v3.end());//������ ������ �������� ���� ���� ������ ������ Ƚ���� ���� ����
	fclose(pFile);
	a.clear();
	iss.clear();
}
//ū ���� ũ���� trigram�� ���� �� ����Ѵ�.
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
//�Է������� ���̱׷����� ������ش�.
void makeBigram(const char* _path, const char* _pathResult) {
	FILE * pFile = fopen(_path, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	//read size of file
	fseek(pFile, 0, SEEK_END);// ���� �����͸� ������ ������ �̵�
	long lSize = ftell(pFile);// ���� ���ۺ��� �� �������� �Ÿ��� return
	fseek(pFile, 0, SEEK_SET);// ���� �����͸� ������ ó������ �̵�

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
//�Է� ������ Ʈ���̱׷����� ������ش�.
void makeTrigram(const char* _path, const char* _pathResult) {
	FILE * pFile = fopen(_path, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	//read size of file
	fseek(pFile, 0, SEEK_END);// ���� �����͸� ������ ������ �̵�
	long lSize = ftell(pFile);// ���� ���ۺ��� �� �������� �Ÿ��� return
	fseek(pFile, 0, SEEK_SET);// ���� �����͸� ������ ó������ �̵�

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
				temp += (data3); //���� $$data�̴� �̴� 3���� �ܾ ���������̴�
				if (!(iss2 >> data2)) break;
				else if (!(iss2 >> data1)) {
					temp += (data3 + data2+"\r\n"); //�ι�° $data3data2  �̴� 3���� �ܾ ���������̴�
					temp += (data3+ data2+ "\r\n");//���忡 �ܾ 2���� �ֱ⶧���� ����������
					temp += (data2+ "\r\n");//���忡 �ܾ 2���� �ֱ⶧���� ����������
					break;
				}
				else {
					temp += (data3 + data2 + "\r\n");//���ο� �ܾ 3�� �̻��� ��Ȳ�̴�.
					temp += ( data3 + data2+data1 + "\r\n");//dat3 data2 data1�� ���� �� �ܾ� ���� �Ҵ� �ȴ�.
				}
			}
			else 
			{
				data3 = data2;
				data2 = data1;
				//�ܾ���� ��ĭ�� �����ش�. data3(1),data2(2),data1(3)�̶��, data3(2)data2(3)data1(data ��� ������) �̴�. 					
				if ((iss2 >> data1))//data1�� �ܾ ���´�. ���� �װ�� data3(2),data2(3),data4(4)�� ���� �ܾ �Ҵ�ȴ�.
				{
					temp += (data3 + data2 + data1 + "\r\n");
				}
				else 
				{//�� ���ο� ���̻� �ܾ ���� ��� ������ �ȴ�. ������ data3 data2���� �ܾ �������� �̴� Ʈ���̱׷����� ����� �ش�.
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
//���ϱ׷����� ���ϴ� �ܾ��� �� ���� ã�� �� ����Ѵ�.
//���� ũ���� ���̱׷����� ���ϴ� �ܾ��� �� ���� ã�� �� ����Ѵ�.
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
//���� ũ���� Ʈ���̱׷����� ���ϴ� �ܾ��� �� ���� ã�� �� ����Ѵ�.
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
//ū �������� ���̱׷� Ȯ���� ���� �� ����Ѵ�.
void hugeBigram(const char* _unigram, const char* _bigram)
{
	
	string temp;
	string temp2;
	int prob;

	cout << "���̱׷��� �Է��ϼ���: "; //�Է½� ��ġ ���� �� ���� space���� �ش�.
	cin >> temp >> temp2;
	uniFileRead(_unigram);
	cout << "���ϱ׷� �б� �Ϸ�" << "\n";
	prob = uniFind(temp);
	v.clear();
	temp += temp2;
	v.clear();
	hugeBiFileRead(_bigram,temp2);
	cout << "���̱׷� �б� �Ϸ�" << "\n";
	cout << temp << " Ȯ����: " << (double)(hugeBi + 1) / (prob + bitotal) << "\n";
	
}
//ū �������� Ʈ���̱׷� Ȯ���� ���� �� ����Ѵ�.
void hugeTrigram(const char* _bigram, const char* _trigram)
{
	string temp;
	string temp2;
	string temp3;

	cout << "Ʈ���̱׷��� �Է��ϼ���: "; //�Է½� ��� ��� ���� �� ���� space���� �ش�.
	cin >> temp >> temp2>>temp3;
	v.clear();
	temp += temp2;
	hugeBiFileRead(_bigram, temp);
	cout << "���̱׷� �б� �Ϸ�" << "\n";
	temp += temp3;
	hugeTriFileRead(_trigram, temp);
	cout << "Ʈ���̱׷� �б� �Ϸ�" << "\n";
	cout << temp << " Ȯ����: " << (double)(hugeTri + 1) / (hugeBi + tritotal) << "\n";
}
//���̱׷��� Ȯ���� ���� �� ����Ѵ�.
void bigram()
{
	string temp;
	string temp2;

	stringstream ss;
	int prob;
	cout << "���̱׷��� �Է��ϼ���: ";
	cin >> temp>>temp2;
	
	prob = uniFind(temp);
	temp += temp2;
	cout << temp <<" Ȯ����: " << (double) (biFind(temp)+1)/ (prob+v.size());
}
//���� �������� ���ϱ׷� Ȯ���� ���� �� ����Ѵ�.
void unigramSentence(const char* _path, const char* _targetPath, const char* _pathResult)
{
	uniFileRead(_path);//���ϱ׷��� �д´�.
	cout << "���ϱ׷� �б� �Ϸ�" << endl;
	FILE * pFile = fopen(_targetPath, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	fseek(pFile, 0, SEEK_END);// ���� �����͸� ������ ������ �̵�
	long lSize = ftell(pFile);// ���� ���ۺ��� �� �������� �Ÿ��� return
	fseek(pFile, 0, SEEK_SET);// ���� �����͸� ������ ó������ �̵�

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
	cout << "���ϱ׷� Ȯ�� �м� �Ϸ�" << "\n\n";
	myfile.close();
	v.clear();

}
//���� �������� Ʈ���̱׷� Ȯ���� ���� �� ����Ѵ�.
void bigramSentence(const char* _unipath, const char* _bipath, const char* _targetPath, const char* _pathResult)
{
	uniFileRead(_unipath);//���ϱ׷��� �д´�.
	cout << "���ϱ׷� �б� �Ϸ�" << endl;
	biFileRead(_bipath);//���̱׷��� �д´�.
	cout << "���̱׷� �б� �Ϸ�" << endl;
	FILE * pFile = fopen(_targetPath, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	fseek(pFile, 0, SEEK_END);// ���� �����͸� ������ ������ �̵�
	long lSize = ftell(pFile);// ���� ���ۺ��� �� �������� �Ÿ��� return
	fseek(pFile, 0, SEEK_SET);// ���� �����͸� ������ ó������ �̵�

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
	cout << "���̱׷� Ȯ�� �м� �Ϸ�" << "\n\n";
	v.clear();
	v2.clear();
}
void trigramSentence(const char* _bipath, const char* _tripath, const char* _targetPath, const char* _pathResult)
{
	biFileRead(_bipath);//���̱׷��� �д���.
	cout << "���̱׷� �б� �Ϸ�" << endl;
	triFileRead(_tripath);//Ʈ���̱׷��� �д´�
	cout << "Ʈ���̱׷� �б� �Ϸ�" << endl;
	FILE * pFile = fopen(_targetPath, "rb");
	fstream myfile;
	myfile = fstream(_pathResult, std::ios::out | std::ios::binary | std::ios::app);

	fseek(pFile, 0, SEEK_END);// ���� �����͸� ������ ������ �̵�
	long lSize = ftell(pFile);// ���� ���ۺ��� �� �������� �Ÿ��� return
	fseek(pFile, 0, SEEK_SET);// ���� �����͸� ������ ó������ �̵�

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
	cout << "Ʈ���̱׷� Ȯ�� �м� �Ϸ�" << "\n\n";
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
	cout << "Ʈ���̱׷��� �Է��ϼ���: ";
	cin >> temp>>temp2>>temp3;
	temp += temp2;
	prob = biFind(temp);
	temp += temp3;
	cout << temp << " Ȯ����: " << (double)(triFind(temp) + 1) / (prob + bitotal);
} 
void compareSentence(const char* _path1, const char* _path2)
{
	FILE * pFile = fopen(_path1, "rb");
	FILE * pFile2 = fopen(_path2, "rb");
	fstream myfile;
	

	fseek(pFile, 0, SEEK_END);// ���� �����͸� ������ ������ �̵�
	long lSize = ftell(pFile);// ���� ���ۺ��� �� �������� �Ÿ��� return
	fseek(pFile, 0, SEEK_SET);// ���� �����͸� ������ ó������ �̵�

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

	fseek(pFile2, 0, SEEK_END);// ���� �����͸� ������ ������ �̵�
	long lSize2 = ftell(pFile2);// ���� ���ۺ��� �� �������� �Ÿ��� return
	fseek(pFile2, 0, SEEK_SET);// ���� �����͸� ������ ó������ �̵�

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
	
	cout << "testK�� �� ���� Ȯ�� ���� ������ ������ : " << count1 << endl;
	cout << "testN�� �� ���� Ȯ�� ���� ������ ������ : " << count2 << "\n\n";
}
 
int main()
{
	

	char * uniKfile = "C:/Users/jangy/Desktop/test/kresult1.txt";//���ϱ׷� �˻��� ���� ����.
	char * uniNfile = "C:/Users/jangy/Desktop/test/nresult1.txt";//���ϱ׷� �˻��� ���� ����.
	char * uniKresult = "C:/Users/jangy/Desktop/test/uniKresult.txt";
	char * uniNresult = "C:/Users/jangy/Desktop/test/uniNresult.txt";
	char * sourceK = "C:/Users/jangy/Desktop/test/bigramKSource.txt";//���̱׷�,Ʈ���̱׷����� ������� ����.
	char * sourceN = "C:/Users/jangy/Desktop/test/bigramNSource.txt";//���̱׷�,Ʈ���̱׷����� ������� ����.
	char * BigramK = "C:/Users/jangy/Desktop/test/BigramK.txt";//K �� ���̱׷�
	char * BigramN = "C:/Users/jangy/Desktop/test/BigramN.txt";//N �� ���̱׷�
	char * BigramKWord = "C:/Users/jangy/Desktop/test/BigramK2.txt";//K �� ���̱׷� wordcount ���
	char * BigramNWord = "C:/Users/jangy/Desktop/test/BigramN2.txt";//N�� ���̱׷� wordcount ���
	char * BigramKResult = "C:/Users/jangy/Desktop/test/BigramKResult.txt";//K �� ���̱׷� �м� ������
	char * BigramNResult = "C:/Users/jangy/Desktop/test/BigramNResult.txt";//N �� ���̱׷� �м� ������ 
	char * TrigramK = "C:/Users/jangy/Desktop/test/TrigramK.txt";//K�� Ʈ���̱׷�
	char * TrigramN = "C:/Users/jangy/Desktop/test/TrigramN.txt";//N�� Ʈ���̱׷�	
	char * TrigramKWord = "C:/Users/jangy/Desktop/test/TrigramK2.txt";//K �� Ʈ���̱׷� wordcount ���
	char * TrigramNWord = "C:/Users/jangy/Desktop/test/TrigramN2.txt";//N�� ���̱׷� wordcount ���
	char * TrigramKResult = "C:/Users/jangy/Desktop/test/TrigramKResult.txt";//K �� Ʈ���̱׷� �м� ������
	char * TrigramNResult = "C:/Users/jangy/Desktop/test/TrigramNResult.txt";//N �� Ʈ���̱׷� �м� ������

	
	cout << "���̱׷� Ȯ�� ��" << endl;
	compareSentence(uniKresult, uniNresult);
	cout << "���ϱ׷� Ȯ�� ��" << endl;
	compareSentence(BigramKResult, BigramNResult);
	cout << "Ʈ���̱׷� Ȯ�� ��" << endl;
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
/*	char * makebifile = "C:/Users/jangy/Desktop/tmp/biResult.txt";//���̱׷����� ������� ����
	char * bifile = "C:/Users/jangy/Desktop/tmp/midResult.txt";//���̱׷� ����
	char * maketrifile = "C:/Users/jangy/Desktop/tmp/triResult.txt";//Ʈ���̱׷����� ������� ����
	char * trifile = "C:/Users/jangy/Desktop/tmp/lastResult.txt";//wordcount�� ���� Ʈ���̱׷�����
	int check;
	int check2;
	cout << "1. ���� �ؽ�Ʈ ���� �м� 2. ū �ؽ�Ʈ ���� �м� 3. ���̱׷����� ���� ����� 4.Ʈ���̱׷� ���� �����: ";
	cin >> check;
	if (check == 1) {
		cout << "1. ���ϱ׷� �м� 2. ���̱׷� �м� 3. Ʈ���� �׷� �м�: ";
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
				cout << "���ϱ׷� �б� �Ϸ�" << "\n";
				biFileRead(bifile);
				cout << "���̱׷� �б� �Ϸ�" << "\n";
				bigram();
			}
		}
		else if (check2 == 3) {
			if (v2.size() > 1) triFileRead(trifile);
			else {
				biFileRead(bifile);
				cout << "���̱׷� �б� �Ϸ�" << "\n";
				triFileRead(trifile);
				cout << "Ʈ���̱׷� �б� �Ϸ�" << "\n";
				trigtam();
			}
		}
		else cout << "�߸��� �Է��Դϴ�" << "n";
	}
	else if (check == 2) {
		cout << "1. ���ϱ׷� �м� 2. ���̱׷� �м� 3. Ʈ���� �׷� �м�: ";
		cin >> check2;
		if (check2 == 1) {
			uniFileRead(unifile);
			cout << "���ϱ׷� �б� �Ϸ�" << "\n";
			unigram();
		}
		else if (check2 == 2) {
			hugeBigram(unifile, bifile);
		}
		else if (check2 == 3) {
			hugeTrigram(bifile, trifile);
		}
		else cout << "�߸��� �Է��Դϴ�" << "n";
	}
	else if (check == 3) {
		makeBigram(source, makebifile);
	}
	else if (check == 4) {
		makeTrigram(source, maketrifile);
	}
	else cout << "�߸��� �Է��Դϴ�." << "\n";
	*/
}