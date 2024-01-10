from flask import Flask, render_template, request, jsonify
from chatbot import Chatbot

app = Flask(__name__)
chatbot = Chatbot()

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/get_response", methods=["POST"])
def get_response():
    user_input = request.json["user_input"]
    response = chatbot.get_response(user_input) 
    return jsonify({"response": response})

if __name__ == "__main__":
    app.run(debug=True)
