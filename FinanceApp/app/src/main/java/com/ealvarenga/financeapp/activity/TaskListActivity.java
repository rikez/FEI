package com.ealvarenga.financeapp.activity;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.ContextMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import com.ealvarenga.financeapp.DAO.TaskDAO;
import com.ealvarenga.financeapp.R;
import com.ealvarenga.financeapp.adapter.TaskListAdapter;
import com.ealvarenga.financeapp.model.Task;

import java.util.List;

/**
 * Created by ealvarenga on 24/11/17.
 */

public class TaskListActivity extends AppCompatActivity {

    private ListView taskList;
    private Button btnCreateTask;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.task_list_item);

        taskList = (ListView) findViewById(R.id.taskListView);
        btnCreateTask = (Button) findViewById(R.id.create_task);

        loadTaskLists();

        taskList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                Task task = (Task) taskList.getItemAtPosition(i);
                Intent intent = new Intent(TaskListActivity.this, TaskFormActivity.class);
                intent.putExtra("task", task);
                startActivity(intent);
            }
        });
        btnCreateTask.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(TaskListActivity.this, TaskFormActivity.class);
                startActivity(intent);
            }
        });
        registerForContextMenu(taskList);

    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, final ContextMenu.ContextMenuInfo menuInfo) {
        MenuItem delete = menu.add("Remove task");

        delete.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
            @Override
            public boolean onMenuItemClick(MenuItem menuItem) {
                AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) menuInfo;
                Task task = (Task) taskList.getItemAtPosition(info.position);
                TaskDAO taskDAO = new TaskDAO(TaskListActivity.this);
                taskDAO.delete(task.getTaskId());

                loadTaskLists();
                return false;
            }
        });
    }

    private void loadTaskLists() {
        TaskDAO taskDAO = new TaskDAO(this);
        List<Task> tasks = taskDAO.findAll();
        TaskListAdapter taskListAdapter = new TaskListAdapter(this, tasks);
        taskList.setAdapter(taskListAdapter);
    }

    @Override
    protected void onRestart() {
        super.onRestart();
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
    }

}
