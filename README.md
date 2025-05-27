# DAA Q2

### Group Member :
Nur Azizah - 5025211252 ()
Aul  
Andin

## About

**The Tic Tac Toe game** is a classic two-player game where the objective is to form a straight line (horizontal, vertical, or diagonal) with three marks (X or O) on a 3x3 grid. This implementation of Tic Tac Toe is designed for a single player to compete against a bot. The game provides a console interface for user interaction.

## Design

### 1. Program Structure:

The program is written in C and consists of several functions to handle different aspects of the game such as displaying the main screen, drawing the game board, initializing the game state, checking for game results, and determining the bot's moves.

### 2. Key Components:

- `arr[3][3]`: A 3x3 character array that represents the game board. Each cell can be '.', 'X', or 'O'.
- `mainScreen()`: Displays the main menu of the game, simplified to only display the Player vs Bot option.
- `gameBoard(const char* P1, const char* P2)`: Renders the current state of the game board along with player names.
- `init()`: Initializes the game board to its default empty state (all cells set to '.').
- `result()`: Checks the current state of the board and returns the result of the game ('X' if Player 1 wins, 'O' if the Bot wins, 'T' for a draw, and '-' if the game is still ongoing).
- Bot move functions for different difficulty levels:
  - `botMoveEasy()`: Selects moves randomly.
  - `botMoveMedium()`: Selects winning moves if possible, blocks player's winning moves, otherwise random.
  - `botMoveHard()`: Uses the Minimax algorithm to choose the optimal move.
- `minimax(bool isBotTurn)`: Implements the DFS-based Minimax algorithm to evaluate the best move.
- `main()`: The main game loop, handling player input, bot moves according to difficulty, and displaying results.

### 3. Game Flow:

- The game starts with displaying the main menu.
- The player chooses whether the bot goes first.
- The player selects the bot difficulty level: Easy, Medium, or Hard.
- The game alternates between player and bot moves until there is a win or a draw.
- After the game ends, the player can choose to play again or exit.

### 4. Bot Logic and Difficulty Levels:

The bot supports three difficulty levels:

- **Easy:** The bot randomly selects an available move on the board.
- **Medium:** The bot tries to win immediately if possible, blocks the player's immediate winning moves, otherwise picks randomly.
- **Hard:** The bot uses the Minimax algorithm (DFS-based) to choose the best possible move, making it an optimal and unbeatable opponent.

## Analysis

### 1. Game Mechanics:

- The game correctly alternates turns between the player and the bot.
- It checks for invalid moves and prompts the player to input a valid move.
- The game ends when there is a win or a draw, and it correctly identifies and displays the result.

### 2. Bot Strategy:

- The Easy level provides a simple random opponent.
- The Medium level introduces basic tactical awareness by looking for immediate wins or blocks.
- The Hard level employs a DFS-based Minimax algorithm, ensuring the bot never loses and plays optimally.

### 3. User Interaction:

- The console-based interface remains straightforward with prompts for player input and difficulty selection.
- Input validation ensures moves are within bounds and cells are empty.

### 4. Code Efficiency:

- The code is modular with separate functions for board management, result checking, and bot moves.
- The Minimax implementation explores the game tree recursively using DFS.
- The Medium level balances efficiency and competitiveness with a heuristic approach.

## Algorithms Used in the Tic Tac Toe Game

### 1. Random Move Selection (Easy Level):

The bot selects moves randomly from available empty cells.

```
srand(time(0));
while (1) {
    x = rand() % 3;
    y = rand() % 3;
    if (arr[x][y] == '.') break;
}
arr[x][y] = 'O';
```

### 2. Immediate Win/Block Heuristic (Medium Level):
The bot checks if it can win immediately or needs to block the player from winning next move; if neither is possible, it selects randomly.

```
bool tryMove(char player, int* moveX, int* moveY) {
    // Tries moves to see if player can win/block immediately.
}
```

### 3. Minimax Algorithm (Hard Level):
A DFS-based backtracking algorithm recursively evaluates all possible future moves to select the optimal one.

Returns +10 for a bot win, -10 for a player win, 0 for a draw.

The bot picks the move that maximizes its minimum gain, ensuring optimal play.

```
int minimax(bool isBotTurn) {
    // DFS recursion exploring game tree states.
}
```

### Summary
- The game supports multiple bot difficulty levels to provide different challenge tiers.

- The Minimax implementation enables the bot to play perfectly at the Hard level.

- The addition of difficulty selection enriches gameplay and learning experience.