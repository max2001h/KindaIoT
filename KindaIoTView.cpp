const char* htmlPage = R"(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Kinda IoT</title>
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons/font/bootstrap-icons.css">
    <style>
        body {
            display: flex;
            flex-direction: column;
            min-height: 100vh;
        }
        main {
            flex: 1;
        }
    </style>
</head>
<body>
    <!-- Header -->
    <header class="bg-primary text-white py-3">
        <div class="container d-flex align-items-center">
            <i class="bi bi-cloud-fill me-2" style="font-size: 1.5rem;"></i>
            <h1 class="m-0">Kinda IoT</h1>
        </div>
    </header>

    <!-- Main Content -->
    <main class="container my-5">
        <!-- Lights Section -->
        <section class="mb-5">
            <h2>Lights</h2>
            <div class="d-flex gap-3">
                <button class="btn btn-success" id="lights-on">ON</button>
                <button class="btn btn-danger" id="lights-off">OFF</button>
            </div>
        </section>

        <!-- Fan Section -->
        <section class="mb-5">
            <h2>Fan</h2>
            <label for="fan-speed" class="form-label">Rotation Speed</label>
            <div class="d-flex align-items-center gap-3">
                <input type="range" class="form-range" id="fan-speed" min="0" max="100" value="0" step="5">
                <button class="btn btn-primary" id="fan-set">SET</button>
            </div>
        </section>

        <!-- Text Section -->
        <section class="mb-5">
            <h2>Text on the screen</h2>
            <div class="d-flex gap-3">
                <input type="text" class="form-control" id="text-input" placeholder="Enter text">
                <button class="btn btn-primary" id="text-set">SET</button>
            </div>
        </section>
    </main>

    <!-- Footer -->
    <footer class="bg-dark text-white text-center py-3">
        <p class="m-0">&copy; Maksym Hryhlevych, 2024</p>
    </footer>

    <!-- Bootstrap JS -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.bundle.min.js"></script>

    <script>
        function sendGetRequest(endpoint) {
            const url = endpoint;
            fetch(url)
                .then(response => response.json())
                .then(data => {
                    console.log("Response:", data);
                })
                .catch(error => {
                    console.error("Error:", error);
                });
        }

        document.getElementById('lights-on').addEventListener('click', () => {
            sendGetRequest('/api/lights/on');
        });

        document.getElementById('lights-off').addEventListener('click', () => {
            sendGetRequest('/api/lights/off');
        });

        document.getElementById('fan-set').addEventListener('click', () => {
            const speed = document.getElementById('fan-speed').value;
            sendGetRequest(`/api/fan?speed=${speed}`);
        });

        document.getElementById('text-set').addEventListener('click', () => {
            const text = document.getElementById('text-input').value;
            sendGetRequest(`/api/text?text=${encodeURIComponent(text)}`);
        });
    </script>
</body>
</html>

)";