#include "../net/net.cpp"
int main(){
    std::vector<net> v = get_net();
    for (int i = 0; i < v.size(); i++)
    {
        std::cout<<v[i].ifname<<" "<<v[i].iftype<<" "<<v[i].mac<<" "<<v[i].ip<<" "<<v[i].mask<<" "<<v[i].broadcast<<" "<<v[i].gateway<<" "<<v[i].upload_speed<<" "<<v[i].download_speed<<" "<<v[i].upload_bytes<<" "<<v[i].download_bytes<<std::endl;
    }
}