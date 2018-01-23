package com.ealvarenga.financeapp.activity;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.ealvarenga.financeapp.DAO.TaskDAO;
import com.ealvarenga.financeapp.R;
import com.ealvarenga.financeapp.model.Task;
import com.mobsandgeeks.saripaar.ValidationError;
import com.mobsandgeeks.saripaar.Validator;
import com.mobsandgeeks.saripaar.annotation.NotEmpty;

import java.util.Calendar;
import java.util.List;

/**
 * Created by ealvarenga on 25/11/17.
 */

public class TaskFormActivity extends AppCompatActivity implements Validator.ValidationListener {

    @NotEmpty(message = "Give a name to the task")
    private EditText name;

    @NotEmpty(message = "Please, describe the task")
    private EditText description;
    private Button btnCreate;
    private Validator v;

    private TaskDAO taskDAO;
    private Task task;

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.task_form);
        taskDAO = new TaskDAO(this);
        name = (EditText) findViewById(R.id.task_name);
        description = (EditText) findViewById(R.id.task_desc);
        btnCreate = (Button) findViewById(R.id.btn_create);

        Intent intent = getIntent();
        task = (Task) intent.getSerializableExtra("task");

        if(task != null) {
            name.setText(task.getName());
            description.setText(task.getDescription());
        }


        v = new Validator(this);
        v.setValidationListener(this);

        btnCreate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                v.validate();
            }
        });
    }

    @Override
    public void onValidationSucceeded() {
        Task taskInstance = new Task(
                this.name.getText().toString(),
                this.description.getText().toString(),
                Calendar.getInstance(),
                Calendar.getInstance()
        );

        if(task != null) {
            taskInstance.setTaskId(task.getTaskId());
            taskDAO.update(taskInstance);
            Toast.makeText(this, "Task updated!", Toast.LENGTH_SHORT).show();
        } else {
            taskDAO.save(taskInstance);
            Toast.makeText(this, "Task created!", Toast.LENGTH_SHORT).show();
        }
        finish();
        startActivity(new Intent(this, TaskListActivity.class));
    }

    public void onValidationFailed(List<ValidationError> errors) {
        for (ValidationError error : errors) {
            View view = error.getView();
            String message = error.getCollatedErrorMessage(this);

            // Display error messages ;)
            if (view instanceof EditText) {
                ((EditText) view).setError(message);
            } else {
                Toast.makeText(this, message, Toast.LENGTH_LONG).show();
            }
        }
    }
}
