# postgresql

## Table

```sql
create table <table-name> (
    id int,
    name varchar(255)
);
```

Read more about [postgresql-create-table](https://www.postgresqltutorial.com/postgresql-tutorial/postgresql-create-table/)

### foreign key array

```sql
CREATE TABLE PKTABLEFORARRAY (
    ptest1 float8 PRIMARY KEY,
    ptest2 text
);
CREATE TABLE FKTABLEFORARRAY (
    ftest1 int[],
    FOREIGN KEY (EACH ELEMENT OF ftest1) REFERENCES PKTABLEFORARRAY,
    ftest2 int
);
```

read more about [postgresql-array-of-elements-that-each-are-a-foreign-key](https://stackoverflow.com/questions/41054507/postgresql-array-of-elements-that-each-are-a-foreign-key)

## conf file

mac default path

```shell
# intel cpu
/usr/local/var/postgres/
# m1
/opt/homebrew/var/postgres/postgresql.conf
```

### read more about conf

- [cannot-find-pg-hba-conf-and-postgreql-conf-file-on-os-x](https://stackoverflow.com/questions/33015471/cannot-find-pg-hba-conf-and-postgreql-conf-file-on-os-x)
