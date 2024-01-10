# Chatbot Project

This project implements a simple chatbot using Python and Flask. The chatbot can perform various tasks such as answering questions, telling jokes, performing calculations, providing the current time, suggesting games, and attempting to cheer up the user with a funny picture.

## Files

### chatbot.py

This file contains the implementation of the `Chatbot` class, which encapsulates the chatbot's functionality. The chatbot responds to user input based on predefined rules and offers a range of features.

#### Features:

- Responds to greetings.
- Answers basic queries.
- Tells jokes for entertainment.
- Performs basic calculations.
- Provides the current time.
- Suggests games when the user is bored.
- Attempts to cheer up the user with a funny picture.

### app.py

This file sets up a Flask web application to interact with the chatbot. It includes routes to serve the HTML interface and handle user input asynchronously.

#### Endpoints:

- `/`: Renders the HTML interface.
- `/get_response`: Accepts user input via POST request, processes it with the chatbot, and returns the chatbot's response.

### index.html

This HTML file defines the structure of the chatbot interface. It includes a chat window where messages are displayed, a user input area, and a button to send messages. JavaScript handles user interactions and communicates with the Flask backend to get responses from the chatbot.

## Usage

1. Install the required packages by running:

   ```bash
   pip install flask
Run the Flask application:
python app.py

2. Open your web browser and navigate to http://127.0.0.1:5000/ to interact with the chatbot.

### Note
The chatbot responds to various inputs, including greetings, questions, and specific keywords.
To exit the chat, type 'exit'.
The chatbot is integrated into a simple web interface using Flask.
Feel free to explore and expand upon the chatbot's capabilities or enhance the user interface as needed.
