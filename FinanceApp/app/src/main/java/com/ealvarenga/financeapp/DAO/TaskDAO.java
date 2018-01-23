package com.ealvarenga.financeapp.DAO;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.ealvarenga.financeapp.model.Task;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;

/**
 * Created by ealvarenga on 24/11/17.
 */

public class TaskDAO extends BaseDAO {

    public TaskDAO(Context ctx) {
        super(ctx);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        String sql = "CREATE TABLE IF NOT EXISTS tb_task(" +
                "id_task INTEGER NOT NULL PRIMARY KEY, " +
                "name VARCHAR NOT NULL, " +
                "description VARCHAR NOT NULL, " +
                "date_start DATETIME, " +
                "date_end DATETIME" +
                ");";

        sqLiteDatabase.execSQL(sql);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        String sql = "DROP TABLE tb_task;";

        sqLiteDatabase.execSQL(sql);
    }

    public void save(Task task) {
        ContentValues cv = new ContentValues();
        cv.put("name", task.getName());
        cv.put("description", task.getDescription());
        cv.put("date_start", task.getDateStart().getTimeInMillis());
        cv.put("date_end", task.getDateEnd().getTimeInMillis());

        SQLiteDatabase db = getWritableDatabase();

        db.insert("tb_task", null, cv);

    }

    public void update(Task task) {
        ContentValues cv = new ContentValues();
        cv.put("name", task.getName());
        cv.put("description", task.getDescription());
        cv.put("date_start", task.getDateStart().getTimeInMillis());
        cv.put("date_end", task.getDateEnd().getTimeInMillis());

        SQLiteDatabase db = getWritableDatabase();
        String[] args = {Long.toString(task.getTaskId())};
        db.update("tb_task", cv, "id_task = ?", args);
    }


    public void delete(long taskId) {
        SQLiteDatabase db = getWritableDatabase();
        String[] args = {Long.toString(taskId)};
        db.delete("tb_task",  "id_task = ?", args);
    }

    /** JAVA is fucking verbose when dealing with date parsing **/
    public List<Task> findAll() {
        try {
            SQLiteDatabase db = getReadableDatabase();
            String sql = "SELECT * FROM tb_task";
            Cursor cursor = db.rawQuery(sql, null);
            List<Task> tasks = new LinkedList<>();
            if(cursor.moveToFirst()) {
                while(!cursor.isAfterLast()) {
                    tasks.add(
                            new Task()
                                    .setTaskId(cursor.getLong(cursor.getColumnIndexOrThrow("id_task")))
                                    .setName(cursor.getString(cursor.getColumnIndexOrThrow("name")))
                                    .setDescription(cursor.getString(cursor.getColumnIndexOrThrow("description")))
                    );

                    cursor.moveToNext();
                }
            }


            return tasks;
        }
        catch(Exception e) {
            return new LinkedList<>();
        }
    }
}
