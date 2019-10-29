
Employee* employee_new() {
    return Employee *this = malloc(sizeof(Employee));
};


int employee_setId(Employee* this,int id) {
    if( id > 0 ) {
        this->id = id;
    }
};

int employee_getId(Employee* this,int* id) {

};


