import http.server
import socketserver

# Puerto en el que se ejecutará el servidor (3334 en este caso)
PORT = 80

# Crea un manejador de solicitudes HTTP personalizado que muestra "Hola"
class MyHandler(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/plain')
        self.end_headers()
        self.wfile.write(b'Hola')

# Inicia el servidor HTTP con el manejador personalizado
with socketserver.TCPServer(("", PORT), MyHandler) as httpd:
    print(f"Servidor web en el puerto {PORT}")
    # Mantén el servidor en ejecución de forma indefinida
    httpd.serve_forever()

