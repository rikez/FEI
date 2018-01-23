package com.ealvarenga.financeapp.adapter;

import android.content.Context;
import android.support.annotation.NonNull;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.ealvarenga.financeapp.R;
import com.ealvarenga.financeapp.model.Task;

import java.util.Collection;
import java.util.List;

public class TaskListAdapter extends BaseAdapter {

    private final List<Task> tasks;
    private Context ctx;

    public TaskListAdapter(Context ctx, List<Task> tasks) {
        this.tasks = tasks;
        this.ctx = ctx;
    }

    @Override
    public int getCount() {
        return tasks.size();
    }

    @Override
    public Task getItem(int i) {
        return tasks.get(i);
    }

    @Override
    public long getItemId(int i) {
        return tasks.get(i).getTaskId();
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        Task task = tasks.get(i);
        LayoutInflater inflater = LayoutInflater.from(this.ctx);
        View v = inflater.inflate(R.layout.task_list, null);
        TextView taskName = (TextView) v.findViewById(R.id.txt_name);
        TextView taskDesc = (TextView) v.findViewById(R.id.txt_desc);
        taskName.setText(task.getName());
        taskDesc.setText(task.getDescription());
        return v;
    }
}
