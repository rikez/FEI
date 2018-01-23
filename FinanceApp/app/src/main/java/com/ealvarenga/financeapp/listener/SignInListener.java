package com.ealvarenga.financeapp.listener;

import android.content.Context;
import android.view.View;
import android.widget.EditText;

import com.mobsandgeeks.saripaar.Validator;


/**
 * Created by ealvarenga on 24/11/17.
 */

public class SignInListener implements View.OnClickListener {

    private Context ctx;
    private Validator v;
    private EditText email;
    private EditText password;

    public SignInListener(Context ctx, Validator v) {
        this.ctx = ctx;
        this.v = v;
    }

    public String getEmail() {
        return email.getText().toString();
    }

    public SignInListener setEmail(EditText email) {
        this.email = email;
        return this;
    }

    public String getPassword() {
        return password.getText().toString();
    }

    public SignInListener setPassword(EditText password) {
        this.password = password;
        return this;
    }

    @Override
    public void onClick(View view) {
        this.v.validate();
    }
}
