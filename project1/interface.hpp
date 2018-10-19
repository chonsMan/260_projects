#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "label.hpp"
#include <iostream>

struct Interface {
private:
    std::istream & input;
    std::ostream & output;
    Label & label;

public:
    Interface(std::istream & input, std::ostream & output, Label & label)
        : input(input), output(output), label(label) {}

    bool execute() {
        output << "Hello! [a,u,s,r,d,q,?]?" << std::endl;
        char * user_input = getline_allocated(input);
        switch (user_input[0]) {
            case 'a':
                add_artist();
                break;
            case 'u':
                update_song();
                break;
            case 's':
                add_song();
                break;
            case 'r':
                remove_songs();
                break;
            case 'd':
                display();
                break;
            case '?':
                help();
                break;
            case 'q': // quit
                return false;
            default:
                output << "Unrecognized command." << std::endl;;
        }

        input.clear();
        return true;
    }

private:
    void add_artist() {
        output << "What is the name of the artist?" << std::endl;;
        char * artist = getline_allocated(input);
        output << "What is the description" << std::endl;;
        char * description = getline_allocated(input);
        output << "What is the top story?" << std::endl;;
        char * top_story = getline_allocated(input);

        try {
            label.add_artist(artist, description, top_story);
        } catch (std::runtime_error & err) {
            output << err.what() << '\n';
        }

        delete[] artist;
        delete[] description;
        delete[] top_story;
    }

    void add_song() {
        output << "Which artist?" << std::endl;;
        char * artist = getline_allocated(input);
        output << "What song would you like to add?" << std::endl;;
        char * song = getline_allocated(input);
        output << "How long is the song?" << std::endl;;
        float length;
        input >> length;
        input.ignore();
        output << "How many views?" << std::endl;;
        int views;
        input >> views;
        input.ignore();
        output << "How many likes?" << std::endl;
        int likes;
        input >> likes;
        input.ignore();

        try {
            label.add_song(artist, song, length, views, likes);
        } catch (std::runtime_error & err) {
            output << err.what() << std::endl;
        }

        delete[] song;
        delete[] artist;
    }

    void update_song() {
        output << "Which artist?" << std::endl;;
        char * artist = getline_allocated(input);
        output << "Which song?" << std::endl;;
        char * song = getline_allocated(input);
        output << "How many views?" << std::endl;;
        int views;
        input >> views;
        input.ignore();
        output << "How many likes?" << std::endl;
        int likes;
        input >> likes;
        input.ignore();

        try {
            label.update_song(artist, song, views, likes);
        } catch (std::runtime_error & err) {
            output << err.what() << std::endl;
        }

        delete[] song;
        delete[] artist;
    }

    void remove_songs() {
        output << "What are the minimum number of views?" << std::endl;
        int min;
        input >> min;
        input.ignore();
        label.cull(min);
    }

    void display() {
        output << label << std::endl;
    }

    void help(){
        output
            << "a = add artist\n"
            << "u = update song\n"
            << "s = add song\n"
            << "r = remove songs\n"
            << "d = display list\n"
            << "q = quit program" << std::endl;
    }
};

#endif
