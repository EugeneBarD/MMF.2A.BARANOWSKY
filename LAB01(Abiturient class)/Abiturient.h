#ifndef abiturient_h
#define abiturient_h

class Abiturient {
public:
  Abiturient() {}
  Abiturient(char *, char *, char *, char *, int *);
  ~Abiturient(){};

  void SetSurname(char *);
  void SetName(char *);
  void SetPatronymic(char *);
  void SetAdress(char *);
  void SetMarks(int *);

  void SetAbiturient();

  char *GetSurname();
  char *GetName();
  char *GetPatronymic();
  char *GetAdress();
  int *GetMarks();
  int GetMidMark();

  void EnterAbiturient();
  void DisplayAbiturient();

private:
  char surname[32] = "", name[16] = "", patronymic[32] = "", adress[64] = "";
  int marks[6];
  int midMark;
};

#endif