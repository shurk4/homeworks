/*С помощью классов реализуйте программу имитации работы аудиоплеера.
 * В плеере находится несколько аудиозаписей, доступных для воспроизведения.
 * Для них вы должны создать отдельный класс Track.
 * Полями этого класса должны быть: название, дата создания (здесь вы можете использовать тип std::tm) и продолжительность записи в секундах.

Сам плеер тоже реализуйте с помощью класса. Внутри он должен содержать список доступных записей и нужные для логики работы плеера поля.

Пользователь взаимодействует с программой с помощью команд:

Команда play запрашивает у пользователя название записи для воспроизведения и начинает её воспроизведение.
 Воспроизведение симулируется с помощью вывода в консоль всей информации о записи.
 Если произведение какой-то записи уже начато, ничего не происходит.

Команда pause. Ставит запись на паузу, о чём выводит соответствующее сообщение в консоль.
 Если запись уже на паузе или не воспроизводится вовсе, ничего не происходит.

Команда next переходит к следующей записи для воспроизведения.
 Запись при этом выбирается случайно, как будто плеер работает в режиме shuffle.

Команда stop прекращает воспроизведение текущей записи, если таковая имеется.
 Об этом выводится сообщение в консоль.
 Два раза остановить воспроизведение невозможно, так что команда должна срабатывать только в первом случае.

Команда exit — выход из программы.

Советы и рекомендации
        Забудьте про отдельные глобальные функции и используйте возможности классов и методов по максимуму.*/

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>

void fileEror()
{
    std::cout << "Could not open the file!" << std::endl;
}

class Track
{
    std::string name;
    std::tm addDate;
    std::tm duration;

    friend class Player;
};

class Player
{
    bool played = false;
    bool paused = false;
    std::vector<Track> playlist;

public:
    std::string input;

    int find()
    {
        for(int i = 0; i < playlist.size(); i++)
        {
            if(playlist[i].name == input)
            {
                return i;
            }
        }
        return -1;
    }

    void playback(int i)
    {
        std::cout << "Played track Name: " << playlist[i].name << " date: " << std::put_time(&playlist[i].addDate, "%Y/%m/%d %H:%M:%S")
                  << " Duration: " << std::put_time(&playlist[i].duration, "%M:%S") << std::endl;

        played = true;
        paused = false;
    }

    void play()
    {
        if(paused){
            std::cout << "Playback continued" << std::endl;
            paused = false;
        } else if(!played)
        {
            std::cout << "Enter the track name: " << std::endl;
            std::cin >> input;
            if(find() == -1)
            {
                std::cout << "Track " << input << " not found" << std::endl;
            }
            else
            {
                playback(find());
            }
        }
    }

    void pause()
    {
        if(played && !paused)
        {
            std::cout << "Playback is paused" << std::endl;
            paused = true;
        }
    }

    void next()
    {
        playback(std::rand() % playlist.size());
    }

    void stop()
    {
        if(played)
        {
            std::cout << "Playback is stopped" << std::endl;
            played = false;
            paused = false;
        }
    }

    void load()
    {
        std::ifstream file("..\\playlist.txt");
        if(file.is_open())
        {
            int size;
            file >> size;
            playlist.resize(size);
            for (int i = 0; i < playlist.size(); i++) {
                file >> playlist[i].name >> std::get_time(&playlist[i].addDate, "%Y/%m/%d %H:%M:%S")
                     >> std::get_time(&playlist[i].duration, "%M:%S");
            }
            file.close();
            std::cout << "The playlist is loaded" << std::endl;
        }
        else fileEror();
    }

    void save()
    {
        std::ofstream file("..\\playlist.txt");
        if(file.is_open())
        {
            file << playlist.size() << " ";
            for (int i = 0; i < playlist.size(); i++) {
                file << playlist[i].name << " " << std::put_time(&playlist[i].addDate, "%Y/%m/%d %H:%M:%S")
                     << " " << std::put_time(&playlist[i].duration, "%M:%S") << std::endl;
            }
            file.close();
            std::cout << "The playlist has been saved" << std::endl;
        }
        else fileEror();
    }

    // не используется ---------------------------------------------------
    void add()
    {
        std::srand(std::time(nullptr));
        playlist.resize(10);
        for(int i = 0; i < 10; i++)
        {
            playlist[i].name = "Track" + std::to_string(i + 1);

            std::time_t t = std::time(nullptr);
            playlist[i].addDate = *std::localtime(&t);

            std::cout << "Duration: ";
            playlist[i].duration.tm_min = std::rand() %5 + 3;
            playlist[i].duration.tm_sec = std::rand() %60 + 2;

            std::cout << "Added Name: " << playlist[i].name << " date: " << std::put_time(&playlist[i].addDate, "%Y/%m/%d %H:%M:%S")
                      << " Duration: " << std::put_time(&playlist[i].duration, "%M:%S") << std::endl;
        }
    }
    // не используется ---------------------------------------------------

    void list()
    {
        std::cout << "------------ LIST --------------" << std::endl;
        for(int i = 0; i < 10; i++)
        {
            std::cout << "Name: " << playlist[i].name << " date: " << std::put_time(&playlist[i].addDate, "%Y/%m/%d %H:%M:%S")
                      << " Duration: " << std::put_time(&playlist[i].duration, "%M:%S") << std::endl;
        }
        std::cout << "--------------------------------" << std::endl;
    }
};

int main() {
    Player player;

    player.load();

    do{
        std::cout << "Enter the command:" << std::endl;
        std::cin >> player.input;
        if(player.input == "play")
        {
            player.play();
        }
        if(player.input == "pause")
        {
            player.pause();
        }
        if(player.input == "next")
        {
            player.next();
        }
        if(player.input == "list")
        {
            player.list();
        }
        if(player.input == "stop")
        {
            player.stop();
        }
        if(player.input == "exit")
        {
            player.save();
            std::cout << "bye!" << std::endl;
        }
    }while(player.input != "exit");

    return 0;
}
