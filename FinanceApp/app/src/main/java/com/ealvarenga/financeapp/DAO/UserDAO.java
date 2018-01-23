package com.ealvarenga.financeapp.DAO;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.ealvarenga.financeapp.helper.CryptographHelper;
import com.ealvarenga.financeapp.model.User;

import java.util.Arrays;


/**
 * Created by ealvarenga on 24/11/17.
 */

public class UserDAO extends BaseDAO {

    public UserDAO(Context ctx) {
        super(ctx);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        String sql = "CREATE TABLE IF NOT EXISTS tb_user(" +
                "id_user INTEGER NOT NULL PRIMARY KEY, " +
                "name VARCHAR NOT NULL, " +
                "email VARCHAR NOT NULL UNIQUE, " +
                "password VARCHAR NOT NULL" +
                ");";

        sqLiteDatabase.execSQL(sql);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        String sql = "DROP TABLE tb_user;";

        sqLiteDatabase.execSQL(sql);
    }

    public void save(User user) {
        ContentValues cv = new ContentValues();
        cv.put("name", user.getName());
        cv.put("email", user.getEmail());
        cv.put("password", user.getPassword());

        SQLiteDatabase db = getWritableDatabase();

        db.insert("tb_user", null, cv);
    }

    public User findAndAuthenticate(String email, String password) {
        SQLiteDatabase db = getReadableDatabase();
        String sql = "SELECT id_user, email, name FROM tb_user " +
                "WHERE email = ? AND password = ? LIMIT 1";
        String args[] = {email, CryptographHelper.getMD5(password)};
        Cursor cursor = db.rawQuery(sql, args);

        if(cursor.moveToFirst()) {
            User user = new User();
            Log.i("MODEL", cursor.getString(cursor.getColumnIndexOrThrow("name")));
            user.setUserId(cursor.getLong(cursor.getColumnIndexOrThrow("id_user")))
                    .setEmail(email)
                    .setName(cursor.getString(cursor.getColumnIndexOrThrow("name")));

            return user;
        }

        return null;
    }
}
