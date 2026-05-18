#include <iostream>
#include <memory>
#include <string>

class Song
{
private:
    std::string artist;
    std::string title;

public:
    Song(std::string artist, std::string title)
        : artist(std::move(artist)), title(std::move(title))
    {
        std::cout << "[Konstruktor] " << this->artist << " - " << this->title << std::endl;
    }

    ~Song()
    {
        std::cout << "[Destruktor] " << this->artist << " - " << this->title << std::endl;
    }
};

int main()
{
    std::shared_ptr<Song> song1 = std::make_shared<Song>("Michael Jackson", "Beat It");

    std::cout << "Liczba referencji do obiektu song1: " << song1.use_count() << std::endl;
    {
        std::shared_ptr<Song> song2 = song1;
        std::cout << "Liczba referencji do obiektu song1 po utworzeniu song2: " << song1.use_count() << std::endl;
    }
    std::cout << "Liczba referencji do obiektu song1 po wyjsciu z bloku song2: " << song1.use_count() << std::endl;

    {
        std::shared_ptr<Song> song3 = song1;
        std::cout << "Liczba referencji do obiektu song1 po utworzeniu song3: " << song1.use_count() << std::endl;
    }
    std::cout << "Liczba referencji do obiektu song1 po wyjsciu z bloku song3: " << song1.use_count() << std::endl;

    std::cout << "Wyjscie z main (zniknie ostatni wlasciciel) - powinien wywolac sie destruktor" << std::endl;
}