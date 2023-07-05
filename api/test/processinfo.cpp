#include "../process/process.cpp"
int main()
{
    std::vector<process> v = get_pid();
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i].user << " " << v[i].pid << " " << v[i].command << " " << v[i].processperc << " " << v[i].memperc << " " << v[i].start << " " << v[i].time << std::endl;
    }
    const char* a = "code";
    int b = get_pid_by_name(a);
    printf("%d\n",b);
}
