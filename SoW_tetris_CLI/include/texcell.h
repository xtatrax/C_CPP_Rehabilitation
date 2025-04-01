// TextCell

union TextCellstatus{
    char status;
    bool isLock : 1;
    char type :4;
    char color: 3;
};
enum Type{
    // max 16
};
enum Color{
    // max 7
    Default = 0b000,
    R = 0b001,
    G = 0b010,
    B = 0b011,
    C = 0b100,
    M = 0b101,
    Y = 0b110,
    gray = 0b111

};