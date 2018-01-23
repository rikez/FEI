package com.ealvarenga.financeapp.activity;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.ealvarenga.financeapp.DAO.UserDAO;
import com.ealvarenga.financeapp.R;
import com.ealvarenga.financeapp.helper.CryptographHelper;
import com.ealvarenga.financeapp.listener.SignInListener;
import com.ealvarenga.financeapp.model.User;
import com.mobsandgeeks.saripaar.ValidationError;
import com.mobsandgeeks.saripaar.Validator;
import com.mobsandgeeks.saripaar.annotation.Email;
import com.mobsandgeeks.saripaar.annotation.NotEmpty;
import com.mobsandgeeks.saripaar.annotation.Password;

import java.util.List;


public class LoginActivity extends AppCompatActivity implements Validator.ValidationListener{

    private Button btnSignIn;
    private Button btnSignUp;

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
        setContentView(R.layout.login);

        password = (EditText) findViewById(R.id.login_password);
        email = (EditText) findViewById(R.id.login_email);
        btnSignIn = (Button) findViewById(R.id.btn_signin);
        btnSignUp = (Button) findViewById(R.id.btn_signup);
        v = new Validator(this);
        v.setValidationListener(this);

        btnSignIn.setOnClickListener(setSignInListener());
        btnSignUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(LoginActivity.this, SignUpActivity.class));
            }
        });
    }

    private SignInListener setSignInListener() {
        return new SignInListener(this, v)
                .setEmail(email)
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

        User u = userDAO.findAndAuthenticate(
                this.email.getText().toString(),
                this.password.getText().toString()
        );

        if(u != null) {
            Log.i("USER", u.getEmail());
            Toast.makeText(this, "Logged Successfully " + u.getName(), Toast.LENGTH_LONG).show();
            Intent intent = new Intent(this, TaskListActivity.class);
            intent.putExtra("user", u.getName());
            finish();
            startActivity(intent);
            return;
        }

        Toast.makeText(this, "Credentials Not Authorized", Toast.LENGTH_LONG).show();
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
