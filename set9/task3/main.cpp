#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Song
{
private:
    std::wstring artist;
    std::wstring title;

public:
    Song(std::wstring artist, std::wstring title)
        : artist(std::move(artist)), title(std::move(title))
    {
        std::wcout << L"[konstruktor] " << this->artist << L" - " << this->title << std::endl;
    }

    ~Song()
    {
        std::wcout << L"[destruktor] " << this->artist << L" - " << this->title << std::endl;
    }
};

template <typename... Args>
std::unique_ptr<Song> SongFactory(Args &&...args)
{
    return std::make_unique<Song>(std::forward<Args>(args)...);
}

int main()
{
    auto song = SongFactory(L"Michael Jackson", L"Beat It");

    std::vector<std::unique_ptr<Song>> songs;
    songs.push_back(SongFactory(L"Artist 1", L"Song 1"));
    songs.push_back(SongFactory(L"Artist 2", L"Song 2"));
    songs.push_back(SongFactory(L"Artist 3", L"Song 3"));

    for (auto &s : songs)
    {
        (void)s;
    }
}