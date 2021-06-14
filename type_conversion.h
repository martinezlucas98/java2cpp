#define T_ERROR -1
#define T_INT 0
#define T_CHAR 1
#define T_FLOAT 2
#define T_DOUBLE 3
#define T_STRING 4
#define T_BOOL 5

#define N_TYPES 6 // Number of types

struct T_tuple {
    int type;
    int warning;
};

struct T_table {
    int add[N_TYPES][N_TYPES]; // row + col

    int other[N_TYPES][N_TYPES]; //row -*/ col

    // 0 = FALSE, 1 = TRUE, 2 = TRUE WITH WARNING
    int implicit[N_TYPES][N_TYPES]; // row to col

    int add_warnings[N_TYPES][N_TYPES];

    int other_warnings[N_TYPES][N_TYPES];
};


struct T_table casting_table = {
        .add={
            { T_INT,    T_INT,      T_FLOAT,    T_DOUBLE,   T_ERROR,    T_INT     },
            { T_INT,    T_INT,      T_FLOAT,    T_DOUBLE,   T_STRING,   T_INT     },
            { T_FLOAT,  T_FLOAT,    T_FLOAT,    T_DOUBLE,   T_ERROR,    T_FLOAT   },
            { T_DOUBLE, T_DOUBLE,   T_DOUBLE,   T_DOUBLE,   T_ERROR,    T_DOUBLE  },
            { T_STRING, T_STRING,   T_STRING,   T_STRING,   T_STRING,   T_STRING  },
            { T_INT,    T_INT,      T_FLOAT,    T_DOUBLE,   T_ERROR,    T_INT     }
        },

        .other={
            { T_INT,    T_INT,      T_FLOAT,    T_DOUBLE,   T_ERROR,    T_INT     },
            { T_INT,    T_INT,      T_FLOAT,    T_DOUBLE,   T_ERROR,    T_INT     },
            { T_FLOAT,  T_FLOAT,    T_FLOAT,    T_DOUBLE,   T_ERROR,    T_FLOAT   },
            { T_DOUBLE, T_DOUBLE,   T_DOUBLE,   T_DOUBLE,   T_ERROR,    T_DOUBLE  },
            { T_ERROR,  T_ERROR,    T_ERROR,    T_ERROR,    T_ERROR,    T_ERROR   },
            { T_INT,    T_INT,      T_FLOAT,    T_DOUBLE,   T_ERROR,    T_INT     }
        },

        // 0 = FALSE, 1 = TRUE, 2 = TRUE WITH WARNING
        .implicit={
            { 1, 1, 1, 1, 0, 1 },
            { 1, 1, 1, 1, 0, 1 },
            { 2, 2, 1, 1, 0, 2 },
            { 2, 2, 1, 1, 0, 2 },
            { 0, 0, 0, 0, 1, 1 },
            { 1, 1, 1, 1, 0, 1 }
        },
 
        .add_warnings={
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 2, 2, 2, 2, 0, 2 },
            { 0, 0, 0, 0, 0, 0 }
        },

        .other_warnings={
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0 }
        }
        
};

struct T_tuple cast_type(char l_type_char, char r_type_char, char operator){
    struct T_tuple ret;

    int l_type = l_type_char-48;
    int r_type = r_type_char-48;

    switch (operator){
        case '+':
            ret.type = casting_table.add[l_type][r_type];
            ret.warning = casting_table.add_warnings[l_type][r_type];
            break;
        case '0': ; // implicit
            int aux = casting_table.implicit[l_type][r_type];
            ret.type = aux == 0 ? T_ERROR : r_type;
            ret.warning = aux == 2 ? 1 : 0;
            break;
        case '-':
        case '*':
        case '/':
            ret.type = casting_table.other[l_type][r_type];
            ret.warning = casting_table.other_warnings[l_type][r_type];
            break;
        default:
            ret.type = T_ERROR;
            ret.warning = 0;
            break;
    }

    return ret;
}

char *type_to_str(char type_char){
    int type = type_char-48;
    switch (type){
        case T_INT:
            return "INT";
        case T_CHAR:
            return "CHAR";
        case T_FLOAT:
            return "FLOAT";
        case T_DOUBLE:
            return "DOUBLE";
        case T_STRING:
            return "STRING";
        case T_BOOL:
            return "BOOL";
        default:
            return "ERROR";

    }
}