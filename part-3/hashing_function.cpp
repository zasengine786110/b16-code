#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cmath>
using namespace std;

uint32_t custom_hash(const string &str, const uint32_t m){
    vector<int> values;
    long mod = 0;
    for(char c : str){
        values.push_back(int(c));
    }
    for (int i : values){
        long mod_i = i * static_cast<long>(pow(256,i)) % m;
        mod += mod_i;
    }
    //Exploit the modular arithmetic properties
    uint32_t answer = mod % m;
    return answer;
}

int main(){
    cout << custom_hash("ciao", 255) << endl;
    cout << custom_hash("oaic", 255) << endl;
}
// both produce the hash value 4294967294 as expected
