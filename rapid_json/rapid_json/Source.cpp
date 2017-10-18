#include <iostream>  
#include <string>  
#include <fstream>  
//����rapidjson��Ҫͷ�ļ�,rapidjson�ļ��п���������Ŀ¼����������include·�������߼��뵽������  
#include "rapidjson/document.h"  
#include "rapidjson/filereadstream.h"
#include "include\rapidjson\filewritestream.h"
#include "rapidjson/prettywriter.h"  
#include "rapidjson/stringbuffer.h"  
using namespace std;
using namespace rapidjson;  //����rapidjson�����ռ�  

							//дjson�ļ�  
void json_write()
{
	Document doc;
	doc.SetObject();
	Document::AllocatorType &allocator = doc.GetAllocator(); //��ȡ������  
															 //1.����ַ�������  
	doc.AddMember("author", "tashaxing", allocator);
	//2.����������  
	Value array1(kArrayType);//��СΪ4
	for (int i = 0; i<3; i++)
	{
		Value int_object(kObjectType);
		int_object.SetInt(i);
		array1.PushBack(int_object, allocator);
	}
	doc.AddMember("number", array1, allocator);
	//3.��Ӹ��϶���  
	Value object(kObjectType);
	object.AddMember("language1", "C++", allocator);
	object.AddMember("language2", "java", allocator);
	doc.AddMember("language", object, allocator);
	//4.��Ӷ�������͸��϶�������  
	Value array2(kArrayType);
	Value object1(kObjectType);
	object1.AddMember("hobby", "drawing", allocator);
	array2.PushBack(object1, allocator);
	Value object2(kObjectType);
	object2.AddMember("height", 1.71, allocator);
	array2.PushBack(object2, allocator);
	doc.AddMember("information", array2, allocator);
	StringBuffer buffer;
	PrettyWriter<StringBuffer> pretty_writer(buffer);  //PrettyWriter�Ǹ�ʽ����json�������Writer���ǻ��пո�ѹ�����json  
	doc.Accept(pretty_writer);
	//��ӡ����Ļ  
	cout << "the json output:" << endl;
	cout << buffer.GetString() << endl;
	//������ļ�  
	ofstream fout;
	fout.open("test.json");    //����ʹ���Ժ����·������\\����Ŀ¼��test, test.json, test.txt ���У����������ļ���ʽ��׺��ֻҪ���ı��ĵ�  
	fout << buffer.GetString();
	fout.close();
}

//��json�ļ�  
void json_read()
{
	cout << "the json read:" << endl;
	ifstream fin;

		fin.open("test1.json");//�ļ�Ŀ¼

		string str;
		string str_in = "";
		while (getline(fin, str))    //һ��һ�еض����ַ���str_in��  
		{
			str_in = str_in + str + '\n';
		}

		//��������ӡ����  
		Document document;
		document.Parse<0>(str_in.c_str());

		//Value &node1 = document["number"];
		Value &node1 = document["people"];
		cout << "author: " << endl;
		
		if (node1.IsArray()) {
			for (int i = 0; i < node1.Size(); i++)
			{
				
				Value& node1son = node1[i];
				Value& pose = node1son["pose_keypoints"];
				if (pose.IsArray()) {
					for (int j = 0; j < pose.Size(); j++) {

						double pose_key = pose[j].GetDouble();
						cout << pose_key << ",";
					}
					cout << endl;
					
				}
			}
			
			//for (int i = 0; ii++)
		
			//cout << node1.GetInt() << endl;
	}


	/*Value &node2 = document["number"];
	cout << "number: " << endl;
	if (node2.IsArray())
	{
		for (int i = 0; i<node2.Size(); i++)
			cout << '\t' << node2[i].GetInt() << endl;
	}

	Value &node3 = document["language"];
	cout << "language: " << endl;
	Value &tmp = node3["language1"];
	cout << '\t' << "language1: " << tmp.GetString() << endl;
	tmp = node3["language2"];
	cout << '\t' << "language2: " << tmp.GetString() << endl;

	Value &node4 = document["information"];
	cout << "information: " << endl;
	if (node4.IsArray())
	{
		int i = 0;
		Value &data = node4[i];   //ע�⣬�˴��±�����ֻ���ñ����������ó���������node[0]�������  
		cout << '\t' << "hobby: " << data["hobby"].GetString() << endl;
		i = 1;
		data = node4[i];
		cout << '\t' << "height: " << data["height"].GetDouble() << endl;
	}*/

}
int main(int argc, char **argv)
{
	//д���� ����  
	//json_write();
	json_read();
	system("pause");
	return 0;
}