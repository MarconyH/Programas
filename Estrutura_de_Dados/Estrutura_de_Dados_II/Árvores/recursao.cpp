#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;


// Define a struct to represent a client
struct Client {
  std::string name;
  std::string address;
  std::string phone;
};

// Define a struct to represent a product
struct Product {
  std::string name;
  double price;
  int stock;
};

// Define a struct to represent a sale
struct Sale {
  Client client;
  Product product;
  int quantity;
};

int main() {
    int a;
  // Create a vector to store the clients
  std::vector<Client> clients;

  // Create a vector to store the products
  std::vector<Product> products;

  // Create a vector to store the sales
  std::vector<Sale> sales;

  // Load the client data from the file
  std::ifstream client_file("clients.txt");
  std::string name;
  while (std::getline(client_file, name)) {
    std::string address;
    std::getline(client_file, address);
    std::string phone;
    std::getline(client_file, phone);
    clients.push_back({name, address, phone});
  }
  client_file.close();

  // Load the product data from the file
  std::ifstream product_file("products.txt");
  while (std::getline(product_file, name)) {
    double price;
    product_file >> price;
    int stock;
    product_file >> stock;
    products.push_back({name, price, stock});
  }
  product_file.close();

  // Load the sale data from the file
  std::ifstream sale_file("sales.txt");
  while (!sale_file.eof()) {
    int quantity;
    sale_file >> quantity;
    int client_index;
    sale_file >> client_index;
    int product_index;
    sale_file >> product_index;
    sales.push_back({clients[client_index], products[product_index], quantity});
  }
  sale_file.close();

  // Create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Sales Tracker");

  // Run the main loop
  while (window.isOpen()) {
    // Handle events
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }}

    // Clear the window
    window.clear();

    // Draw the sales information
    a = sales.size();
    for (int i = 0; i < a; i++) {
      const Sale& sale = sales[i];
      sf::Text text;
      text.setString(std::to_string(sale.quantity) + " " + sale.product.name + " to " + sale.client.name);
    }
    return 0;
    }
