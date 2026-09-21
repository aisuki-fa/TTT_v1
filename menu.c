int showUrself(){
    printf("TIC-TAC-TOE\n");
    printf("1. Player vs. Player\n2. Player vs. AI1\n3. Player vs. AI2\n4. Player vs. AI3\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}