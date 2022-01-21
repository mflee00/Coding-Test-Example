#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<tuple>
//#include<stdio.h>
//#include<string.h>

using namespace std;
int n_rom;
int n_use;

vector <tuple<string, int, int>> a;
string rom_list[50];

bool check_rom_boot(string rom)
{
	bool no_rom_flag = false;
	for (int i = 0; i < n_rom; i++) {
		auto it = find_if(a.begin(), a.end(), [=](tuple<string, int, int>& e) {return get<0>(e) == rom; });
		if (it != a.end()) {
			no_rom_flag = true;
		}
	}
	return no_rom_flag;
}

int main(int argc, char** argv)
{
	int input_cnt = 1;
	bool time_schedule[10] = { 0, };
	int time_schedule_cnt = 0;
	int avail_cnt = 0;
	bool printf_flag = false;

	//cout<<argc;
	cin >> n_rom;
	cin >> n_use;
	//cout<<n_use;


	//n_rom = atoi(argv[input_cnt++]);
	//n_use = atoi(argv[input_cnt++]);



	for (int i = 0; i < n_rom; i++) {
		cin >> rom_list[i];
		//rom_list[i] = argv[input_cnt++];
	}

	//시간 오름차순 정렬
	sort(rom_list, rom_list + n_rom);

	for (int i = 0; i < n_use; i++) {
		string temp; //= argv[input_cnt + (3 * i) + 0];
		int temp2; //= atoi(argv[input_cnt + (3 * i) + 1]);
		int temp3; //= atoi(argv[input_cnt + (3 * i) + 2]);
		cin >> temp >> temp2 >> temp3;

		a.push_back(make_tuple(temp, temp2, temp3));
	}

	//시간 오름차순 정렬
	sort(a.begin(), a.end());

	for (int i = 0; i < n_rom; i++)
	{
		cout << "Room " << rom_list[i] << ":" << endl;
		if (check_rom_boot(rom_list[i]) == false) {
			cout << "1 available:" << endl << "09-18" << endl;
		}
		else {
			//vector <tuple<string, int, int>> b;
			for (int j = 0; j < n_use; j++) {
				if (get<0>(a[j]) == rom_list[i]) {
					int start = get<1>(a[j]) - 9;
					int end = get<2>(a[j]) - 9;

					for (int k = start; k <= end; k++)
					{
						time_schedule[k] = true;
					}
				}
			}
			string temp;
			//char time[10] = { 0, };
			for (int j = 0; j < 10; j++) {
				if (time_schedule[j] == false) {
					if (printf_flag == false) {
						if (j != 0) {
							//sprintf_s(time, "%02d", (j - 1) + 9);
							if ((j - 1) + 9 < 10)
							{
								temp += "0" + to_string((j - 1) + 9);
							}
							else {
								temp += to_string((j - 1) + 9);
							}

						}
						else {
							if ((j - 1) + 9 < 10)
							{
								temp += "0" + to_string(j + 9);
							}
							else {
								temp += to_string(j + 9);
							}
							//sprintf_s(time, "%02d", j + 9);

						}
						//temp += time;
						//memset(time, 0x00, 10);
						printf_flag = true;
					}

				}
				else {
					if (printf_flag == true) {
						//sprintf_s(time, "- %02d\n", j + 9);
						temp += "-" + to_string(j + 9) + "\n";
						//temp += time;
						//memset(time, 0x00, 10);
						printf_flag = false;
						avail_cnt++;
					}
				}
			}
			if (printf_flag == true) {
				//sprintf_s(time, "- %2d\n", 18);
				temp += "-18\n";
				//temp += time;
				//memset(time, 0x00, 10);
				printf_flag = false;
				avail_cnt++;
			}

			if (avail_cnt == 0) {
				cout << "Not available" << endl;
			}
			else {
				cout << avail_cnt << " " << "available:" << endl << temp;
			}


		}
		if (i != (n_rom - 1)) {
			cout << "-----" << endl;
		}
		avail_cnt = 0;
		for (int m = 0; m < 10; m++)
		{
			time_schedule[m] = 0;
		}
		//memset(time_schedule, 0x00, 10);
	}


	return 0;
}