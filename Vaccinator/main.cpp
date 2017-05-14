#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

void InitializeVaccinations(const vector<wstring>& mutexes)
{
    for (auto& mutex : mutexes)
    {
        if (!mutex.empty())
        {
            CreateMutexW(nullptr, FALSE, mutex.c_str());
        }
    }
}

int main()
{
    vector<wstring> mutexes = { L"MsWinZonesCacheCounterMutexA", L"Global\\MsWinZonesCacheCounterMutexA0" };
    InitializeVaccinations(mutexes);

    Sleep(INFINITE);
    return 0;
}