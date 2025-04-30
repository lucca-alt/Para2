import random


def chooseName():
    name = input("Whats your name?: ").upper()
    return name


def chooseEnemy():
    enemy = input("Who do you want to play against? (AI / Name): ").upper()
    return enemy


def chooseStartingPlayer(name, enemy):
    if random.random() < 0.5:
        startingPlayer = f"{name}"
        return startingPlayer
    else:
        startingPlayer = f"{enemy}"
        return startingPlayer


def printBoard(player):
    print("\n")
    print(f"Turn of player \"{player}\"\n")
    print("    1   2   3")
    print("  -------------")
    print(f"6 | {board[6]} | {board[7]} | {board[8]} |")
    print("  ----+---+----")
    print(f"3 | {board[3]} | {board[4]} | {board[5]} |")
    print("  ----+---+----")
    print(f"0 | {board[0]} | {board[1]} | {board[2]} |")
    print("  -------------")


def playerTurn(symbol, currentPlayer):

    while True:
        if currentPlayer == "AI":  # AI implementation (random)
            move = random.randrange(9)
            if board[move] != " ":
                continue
            else:
                board[move] = symbol
                break

        move = input("Pick your field from 1-9: ")  # normal player

        if move == "quit".lower():  # quit the program
            exit()

        if move not in ["1", "2", "3", "4", "5", "6", "7", "8", "9"]:
            print("Invalid spot, try again: ")
            continue

        move = int(move)

        if board[move - 1] != " ":
            print("Spot already taken, choose another")
            continue
        else:
            board[move - 1] = symbol
            break


def checkGame():
    row1 = (board[6] == board[7] == board[8] != " ")
    row2 = (board[3] == board[4] == board[5] != " ")
    row3 = (board[0] == board[1] == board[2] != " ")
    col1 = (board[0] == board[3] == board[6] != " ")
    col2 = (board[1] == board[4] == board[7] != " ")
    col3 = (board[2] == board[5] == board[8] != " ")
    diag1 = (board[0] == board[4] == board[8] != " ")
    diag2 = (board[2] == board[4] == board[6] != " ")

    if row1 or row2 or row3 or col1 or col2 or col3 or diag1 or diag2:  # check if any winning condition is met
        return "ITS A WIN FOR: "
    elif " " not in board:
        return "ITS A TIE! RESTARTING GAME!!"
    else:
        return "Next move"


def playGame(player1=None, player2=None, startingPlayer=None):
    global board
    board = [" "] * 9

    if player1 is None:  # for first round when players are not yet given
        player1 = chooseName()
    if player2 is None:
        player2 = chooseEnemy()
    if startingPlayer is None:
        currentPlayer = chooseStartingPlayer(player1, player2)
    else:
        currentPlayer = startingPlayer

    symbol = {player1: "X", player2: "O"}

    while True:
        printBoard(currentPlayer)
        playerTurn(symbol[currentPlayer], currentPlayer)

        result = checkGame()
        if result == "ITS A WIN FOR: ":
            printBoard(currentPlayer)
            print(result + currentPlayer)
            break
        elif result == "ITS A TIE! RESTARTING GAME!!":
            print(result)
            switchPlayer = player1 if currentPlayer == player2 else player2
            playGame(player1, player2, startingPlayer=switchPlayer)  # switch
            return  # stop round
        currentPlayer = player1 if currentPlayer == player2 else player2


def main():
    print("\nType 'quit' to exit the game\n")

    while True:
        playGame()

        while True:
            restart = input("Want to play again? (y/n): ").lower()

            if restart == "n":
                print("Bye bye")
                exit()
            elif restart == "y":
                print("Another round!")
                break
            else:
                print("Invalid input, type 'y' or 'n': ")


if __name__ == "__main__":
    main()
