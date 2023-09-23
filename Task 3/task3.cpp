#include <iostream>
#include <vector>
#include <string>

class Movie {
public:
    std::string title;
    int availableSeats;

    Movie(const std::string& _title, int _availableSeats) : title(_title), availableSeats(_availableSeats) {}
};

class Booking {
public:
    std::string movieTitle;
    int numTickets;

    Booking(const std::string& _movieTitle, int _numTickets) : movieTitle(_movieTitle), numTickets(_numTickets) {}
};

class MovieBookingSystem {
private:
    std::vector<Movie> movies;
    std::vector<Booking> bookings;

public:
    void addMovie(const std::string& title, int availableSeats) {
        Movie movie(title, availableSeats);
        movies.push_back(movie);
    }

    void viewMovies() {
        std::cout << "Available Movies:" << std::endl;
        for (const Movie& movie : movies) {
            std::cout << "Title: " << movie.title << " | Available Seats: " << movie.availableSeats << std::endl;
        }
    }

    bool bookMovie(const std::string& title, int numTickets) {
        for (Movie& movie : movies) {
            if (movie.title == title) {
                if (numTickets <= movie.availableSeats) {
                    Booking booking(title, numTickets);
                    bookings.push_back(booking);
                    movie.availableSeats -= numTickets;
                    return true;
                } else {
                    std::cout << "Not enough seats available for " << title << std::endl;
                    return false;
                }
            }
        }
        std::cout << "Movie not found: " << title << std::endl;
        return false;
    }

    void viewBookings() {
        std::cout << "Current Bookings:" << std::endl;
        for (const Booking& booking : bookings) {
            std::cout << "Movie: " << booking.movieTitle << " | Tickets: " << booking.numTickets << std::endl;
        }
    }
};

int main() {
    MovieBookingSystem system;

    // Adding some movies
    system.addMovie("Movie 1", 50);
    system.addMovie("Movie 2", 30);

    int choice;
    do {
        std::cout << "Movie Booking System Menu:" << std::endl;
        std::cout << "1. View Available Movies" << std::endl;
        std::cout << "2. Book a Movie" << std::endl;
        std::cout << "3. View My Bookings" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system.viewMovies();
                break;
            case 2:
                {
                    std::string title;
                    int numTickets;
                    std::cout << "Enter the movie title and number of tickets to book: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    std::cin >> numTickets;
                    system.bookMovie(title, numTickets);
                }
                break;
            case 3:
                system.viewBookings();
                break;
            case 4:
                std::cout << "Exiting the system." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

