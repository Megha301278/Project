import random
from datetime import datetime

class Chatbot:
    def __init__(self):
        self.greetings = ["hello", "hi", "hey", "greetings"]
        self.jokes = ["Why don't scientists trust atoms? Because they make up everything!",
                      "I told my wife she should embrace her mistakes. She gave me a hug.",
                      "Why did the scarecrow win an award? Because he was outstanding in his field!"]
        self.basic_queries = {"how are you": "I'm doing well, thank you!",
                              "who are you": "I'm just a simple chatbot.",
                              "what's your name": "You can call me ChatGPT."}
        self.calculator_operators = {"+": "add", "-": "subtract", "*": "multiply", "/": "divide"}

    def get_response(self, user_input):
        user_input = user_input.lower()

        if any(greeting in user_input for greeting in self.greetings):
            return "Hello! How can I help you today?"

        for query, response in self.basic_queries.items():
            if query in user_input:
                return response

        if "joke" in user_input:
            return random.choice(self.jokes)

        # Check for goodbye phrases
        if any(goodbye in user_input for goodbye in ["bye", "goodbye", "cya", "see you", "farewell"]):
            return "Goodbye! Have a great day."

        # Check for time request
        if "time" in user_input:
            return f"The current time is {datetime.now().strftime('%H:%M')}."

        # Additional functions
        if "name" in user_input:
            return "I'm just a chatbot. You can call me whatever you like!"

        if "thanks" in user_input or "thank you" in user_input:
            return "You're welcome! If you have more questions, feel free to ask."

        if "bored" in user_input:
            return self.suggest_game()

        if "what can you do" in user_input or "capabilities" in user_input:
            return self.list_capabilities()

        # Check for calculation request
        if "calculate" in user_input:
            return self.calculate_expression(user_input)

        return "I'm sorry, I didn't understand that. Can you please ask another question?"

    def calculate_expression(self, user_input):
        try:
            # Extract the numbers from the user's input
            _, num1, operator, num2 = user_input.split()
            num1, num2 = float(num1), float(num2)

            # Perform the calculation based on the operator
            if operator == "+":
                result = num1 + num2
            elif operator == "-":
                result = num1 - num2
            elif operator == "*":
                result = num1 * num2
            elif operator == "/":
                result = num1 / num2

            return f"The result of {num1} {operator} {num2} is {result}."
        except (ValueError, ZeroDivisionError):
            return "Please provide a valid expression for the calculator."


    def list_capabilities(self):
        capabilities = [
            "1. Answer general questions and provide information.",
            "2. Tell jokes to lighten the mood.",
            "3. Perform basic calculations (addition, subtraction, multiplication, division).",
            "4. Provide the current time.",
            "5. Play a simple game (rock, paper, scissors) if you're bored.",
            "6. Attempt to cheer you up with a funny picture if you're sad."
        ]
        return "\n".join(capabilities)
    
    def suggest_game(self):
        games = ["Try solving a puzzle!", "Play a quick online game.", "Read an interesting article."]
        return random.choice(games)

    def get_funny_picture_link(self):
        actual_image_link = "https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.baamboozle.com%2Fgame%2F755880&psig=AOvVaw3GBjAJz_J8OKO0rF-s1Y3l&ust=1704979181978000&source=images&cd=vfe&opi=89978449&ved=0CBMQjRxqFwoTCMiS_tX00oMDFQAAAAAdAAAAABAJ"
        return f"Here's a funny picture to cheer you up: {actual_image_link}"

    def start_chat(self):
        print("Chatbot: Hello! Type 'exit' to end the conversation.")
        while True:
            user_input = input("You: ")
            if user_input.lower() == "exit":
                print("Chatbot: Goodbye!")
                break
            response = self.get_response(user_input)
            print("Chatbot:", response)

if __name__ == "__main__":
    chatbot = Chatbot()
    chatbot.start_chat()
