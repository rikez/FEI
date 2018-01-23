package com.ealvarenga.financeapp.DAO;

import android.content.Context;
import android.database.sqlite.SQLiteOpenHelper;

public abstract class BaseDAO extends SQLiteOpenHelper{

    public static final String DATABASE = "todo_app";
    public static final int VERSION = 2;

    public BaseDAO(Context context) {
        super(context, DATABASE, null, VERSION);
    }
}
