# Pixel Quest: Video Game Character Tracker

A beginner C++ project with a retro website. The website runs the real
C++ program (`main.cpp`) inside the browser using WebAssembly, so anyone
can open the link. No terminal or server needed.

## Files

| File | What it is |
|------|-----------|
| `main.cpp` | The C++ program: the `Character` class, input checks, report, and statistics |
| `index.html` | The website design. It types answers into the C++ program's `cin` and shows what `cout` prints |
| `.github/workflows/website.yml` | Tells GitHub to compile `main.cpp` and publish the site automatically |

## How the website uses the C++

GitHub compiles `main.cpp` into `tracker.js` and `tracker.wasm`. When you
click GENERATE TEAM REPORT, the page runs that program, types each answer
as if you typed it in a terminal, and reads the CHARACTER REPORT and TEAM
STATISTICS from the output. Input errors on the page are the program's own
"Invalid ..." messages. Click SHOW C++ PROGRAM OUTPUT to see the full
console output.

## Input rules (from main.cpp)

- Player name: one word, 1 to 16 characters, no spaces
- Health: whole number from 0 to 100
- Level: whole number from 0 to 999999

## Running the console version on your own computer (optional)

    g++ -o tracker main.cpp
    ./tracker
