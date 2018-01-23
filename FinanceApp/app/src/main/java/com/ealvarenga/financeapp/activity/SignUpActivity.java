package com.ealvarenga.financeapp.activity;

import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.ealvarenga.financeapp.DAO.TaskDAO;
import com.ealvarenga.financeapp.DAO.UserDAO;
import com.ealvarenga.financeapp.R;
import com.ealvarenga.financeapp.listener.SignInListener;
import com.ealvarenga.financeapp.listener.SignUpListener;
import com.ealvarenga.financeapp.model.User;
import com.mobsandgeeks.saripaar.ValidationError;
import com.mobsandgeeks.saripaar.Validator;
import com.mobsandgeeks.saripaar.annotation.Email;
import com.mobsandgeeks.saripaar.annotation.Length;
import com.mobsandgeeks.saripaar.annotation.NotEmpty;
import com.mobsandgeeks.saripaar.annotation.Password;

import java.util.List;

/**
 * Created by ealvarenga on 24/11/17.
 */

public class SignUpActivity extends AppCompatActivity implements Validator.ValidationListener {

    private Button btnSignUpCheck;

    @NotEmpty(message = "Please, type your name")
    @Length(min = 2, max = 55, message = "Minimum of 2 Characters and Maximum of 55")
    private EditText name;

    @NotEmpty(message = "Please, type your e-mail address")
    @Email(message = "E-mail is not valid")
    private EditText email;

    @NotEmpty(message = "Please, type your password")
    @Password(min = 6, message = "Password incorrect")
    private EditText password;

    Validator v;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.signup_form);

        password = (EditText) findViewById(R.id.signup_password);
        email = (EditText) findViewById(R.id.signup_email);
        name = (EditText) findViewById(R.id.signup_name);
        btnSignUpCheck = (Button) findViewById(R.id.btn_signup_check);

        v = new Validator(this);
        v.setValidationListener(this);

        btnSignUpCheck.setOnClickListener(setSignUpListener());
    }

    private SignUpListener setSignUpListener() {
        return new SignUpListener(this, v)
                .setEmail(email)
                .setName(name)
                .setPassword(password);
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


    @Override
    public void onValidationSucceeded() {
        UserDAO userDAO = new UserDAO(this);
        TaskDAO taskDAO = new TaskDAO(this);
        SQLiteDatabase db = taskDAO.getWritableDatabase();
        db.isDatabaseIntegrityOk();
        User fresh = new User(
                this.email.getText().toString(),
                this.password.getText().toString(),
                this.name.getText().toString()
        );
        userDAO.save(fresh);
        Toast.makeText(this, "You have just signed up " + fresh.getName(), Toast.LENGTH_LONG).show();
        finish();
        startActivity(new Intent(this, TaskFormActivity.class));
    }

    @Override
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
