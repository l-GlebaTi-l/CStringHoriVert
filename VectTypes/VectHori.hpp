class CStringHori : public CString {
public:
    CStringHori(char *str) : CString(str){}
    int output(){   //  const char *FileName
        FILE *file = fopen(filename, "w");
        int i = 0;
        while(data[i] != '\0'){
            fprintf(file, "%c", data[i]);
            i++;
        }
        fclose(file);
        return 0;
    }
};

class FactoryCStringHori : public CFabricData{
public:
    CString* Create(char *str){
//        cout << "Hori!" << endl;
        return new CStringHori(str);
    }
};
