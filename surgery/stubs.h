
class ReadlineStub {
public:
    std::vector<std::string> lines;
};


extern "C"
{
    int readline(int fd, char line[]);
    void fetchMarketingSlogans(char const * searchTerm, char* slogans);
}
