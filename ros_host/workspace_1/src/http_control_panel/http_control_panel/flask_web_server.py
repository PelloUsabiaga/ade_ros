from flask import Flask 


class http_control_panel:
    def create_flask_app(self):
        app = Flask(__name__)
        app.add_url_rule("/", "index", self.index_view)
        return app

    def index_view(self):
        return "Hello world"


def main():
    print('Hi from http_control_panel.')
    
    hcp = http_control_panel()

    app = hcp.create_flask_app()
    app.run(host='0.0.0.0')


if __name__ == '__main__':
    main()
