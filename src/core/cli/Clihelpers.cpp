//
// Created by Chang on 2026/1/16.
//
#include "Clihelpers.h"
int slotCharToIndex(char c) {
    if (c >= 'a' && c <= 'i') c = char(c - 'a' + 'A');
    if (c < 'A' || c > 'I') return -1;
    return c - 'A'; // A->0 ... I->8
}

char slotIndexToChar(int idx) {
    return char('A' + idx); // 0->A ... 8->I
}
int readSlotAI(const char* prompt) {
    while (true) {
        std::cout << prompt;
        std::string s;
        std::cin >> s;
        if (s.size() == 1) {
            char c = s[0];
            int idx = slotCharToIndex(c);
            if (idx>=0 && idx<=8) return idx;
        }
        std::cout << "Invalid. Use A-I";
        std::cout << ".\n";
    }
}

void printStatus(const GameState& st) {
    std::cout << "\n=== STATUS ===\n";
    std::cout << "round=" << st.round << "  score(P0,P1)=(" << st.score[0] << "," << st.score[1] << ")\n";
    std::cout << "phase=" << phaseToString(st.phase) << "\n";
    std::cout << "=============\n\n";
}
void p0status(const GameState& st) {
    std::cout<< "score(P0,P1)=(" << st.score[0] << "," << st.score[1] << ")\n";
    std::cout<< "You are Player 0\n";
    std::cout<<"Your cards are:\n";
    std::cout<<"A B C D E F G H I \n";
    for (int i=0; i<9; i++) {
        std::cout<<st.cards[0][i]<<" ";
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        std::cout<<st.tokenSum[0][i]<<" ";
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        if (st.used[0][i]) {
            std::cout<<"# ";
        }
        else {
            std::cout<<"  ";
        }
    }
    std::cout<<"\n";
    std::cout<<"Your opponent's cards are \n";
    std::cout<<"A B C D E F G H I \n";
    for (int i=0; i<9; i++) {
        if (st.revealed[1][i]) {
            std::cout<<st.cards[1][i]<<" ";
        }
        else {
            std::cout<<"* ";
        }
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        std::cout<<st.tokenSum[1][i]<<" ";
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        if (st.used[1][i]) {
            std::cout<<"# ";
        }
        else {
            std::cout<<"  ";
        }
    }
    std::cout<<"\n";
}
void p1status(const GameState& st) {
    std::cout<< "You are Player 1.\n";
    std::cout<< "Your cards are \n";
    std::cout<<"A B C D E F G H I \n";
    for (int i=0; i<9; i++) {
        std::cout<<st.cards[1][i]<<" ";
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        std::cout<<st.tokenSum[1][i]<<" ";
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        if (st.used[1][i]) {
            std::cout<<"# ";
        }
        else {
            std::cout<<"  ";
        }
    }
    std::cout<<"\n";
    std::cout<<"Your opponent's cards are \n";
    std::cout<<"A B C D E F G H I \n";
    for (int i=0; i<9; i++) {
        if (st.revealed[0][i]) {
            std::cout<<st.cards[0][i]<<" ";
        }
        else {
            std::cout<<"* ";
        }
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        std::cout<<st.tokenSum[0][i]<<" ";
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        if (st.used[0][i]) {
            std::cout<<"# ";
        }
        else {
            std::cout<<"  ";
        }
    }
    std::cout<<"\n";
}
void confirmPlayer0() {
    while (true) {
        std::cout <<"Confirm that you are Player 0 by exactly typing \"Yes\".\n";
        std::string s;
        std::cin >> s;
        if (s=="Yes"){
            break;
        }
        std::cout << "Type \"Yes\" whenever you are ready.";
        std::cout << ".\n";

    }
}
void confirmPlayer1() {
    while (true) {
        std::cout <<"Confirm that you are Player 1 by exactly typing \"Yes\".\n";
        std::string s;
        std::cin >> s;
        if (s=="Yes"){
            break;
        }
        std::cout << "Type \"Yes\" whenever you are ready.";
        std::cout << ".\n";

    }
}
void publicP0(const GameState& st) {
    std::cout<<"P0's cards are:\n";
    for (int i=0; i<9; i++) {
        if (st.revealed[0][i]) {
            std::cout<<st.cards[0][i]<<" ";
        }
        else {
            std::cout<<"* ";
        }
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        std::cout<<st.tokenSum[0][i]<<" ";
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        if (st.used[0][i]) {
            std::cout<<"# ";
        }
        else {
            std::cout<<"  ";
        }
    }
    std::cout<<"\n";
}
void publicP1(const GameState& st) {
    std::cout<<"P1's cards are:\n";
    for (int i=0; i<9; i++) {
        if (st.revealed[1][i]) {
            std::cout<<st.cards[1][i]<<" ";
        }
        else {
            std::cout<<"* ";
        }
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        std::cout<<st.tokenSum[1][i]<<" ";
    }
    std::cout<<"\n";
    for (int i=0; i<9; i++) {
        if (st.used[1][i]) {
            std::cout<<"# ";
        }
        else {
            std::cout<<"  ";
        }
    }
    std::cout<<"\n";
}
void doActionUntilLegal(GameState& st, PlayerId p, ActionType type, const char* prompt) {
    while (true) {
        int slot = readSlotAI(prompt);
        Action a{type, slot};
        if (!isLegal(st, p, a)) {
            std::cout << "Illegal move. Try again.\n";
            continue;
        }
        applyAction(st, p, a);
        break;
    }
}
void handlePlaceToken(GameState& st) {
    confirmPlayer0();
    p0status(st);
    doActionUntilLegal(st, P0, PlacePlus, "P0 Place +1 slot (A-I):\n");
    advanceIfReady(st);
    doActionUntilLegal(st, P0, PlaceMinus,"P0 Place -1 slot (A-I):\n");
    advanceIfReady(st);
    confirmPlayer1();
    p1status(st);
    doActionUntilLegal(st, P1, PlacePlus, "P1 Place +1 slot (A-I):\n");
    advanceIfReady(st);
    doActionUntilLegal(st, P1, PlaceMinus,"P1 Place -1 slot (A-I):\n");
    advanceIfReady(st);
}
void handleReveal(GameState& st) {
    confirmPlayer0();
    if (!skipReveal(st, P0)) {
        p0status(st);
        doActionUntilLegal(st,P0,RevealOppSlot, "P0 Reveal opponent slot (A...I):\n" );
    }
    else {
        std::cout<<"P0: You've known Everything!\n";
    }
    markRevealDone(st, P0);
    advanceIfReady(st);
    confirmPlayer1();
    if (!skipReveal(st, P1)) {
        p1status(st);
        doActionUntilLegal(st,P1,RevealOppSlot, "P1 Reveal opponent slot (A...I):\n" );
    }
    else {
        std::cout<<"P1: You've known Everything!\n";
    }
    markRevealDone(st, P1);
    advanceIfReady(st);
    publicP0(st);
    publicP1(st);
}
void handleSelect(GameState& st) {
    confirmPlayer0();
    p0status(st);
    doActionUntilLegal(st, P0, SelectMySlot, "P0 Select slot to play (A-I): ");
    advanceIfReady(st);
    confirmPlayer1();
    p1status(st);
    doActionUntilLegal(st, P1, SelectMySlot, "P1 Select slot to play (A-I): ");
    advanceIfReady(st);
}
void handleResolve(GameState& st) {
    std::vector<int> r=resolveRound(st);
    if (r.size()<5) {
        std::cout<<"Error in HandleResolve.\n";
        return;
    }
    char idx0=slotIndexToChar(r[0]);
    char idx1=slotIndexToChar(r[1]);
    std::cout<<"Cards Selected: \n";
    std::cout<<idx0<<"    "<<idx1<<"\n";
    std::cout<<r[2]<<" VS "<<r[3]<<"\n";
    if (r[4]==0 ||r[4]==1) {
        std::cout<<"Player"<<r[4]<<" Got 1 Score!\n";
    }
    else {
        std::cout<<"Tie!\n";
    }
}
void handleGameOver(const GameState& st) {
    std::cout << "\n=== GAME OVER ===\n";
    std::cout << "Final score: P0=" << st.score[0] << "  P1=" << st.score[1] << "\n";
    if (winner(st)==0 || winner(st)==1) {
        std::cout<<"The Winner is Player "<<winner(st)<<"! ! !\n";
    }
    else if (winner(st)==2 || winner(st)==3) {
        std::cout<<"You are both brilliant!\n "
                   "But according to the rules, the sum of Player"
        <<winner(st)-2<<" 's win cards is smaller.\n"
        <<"The Winner is Player "<<winner(st)-2<<"! ! !\n";
    }
    else if (winner(st)==4) {
        std::cout<<" The game ended in a standoff\n."
        <<"You are both wonderful players!!!\n";
    }
}