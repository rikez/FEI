package com.ealvarenga.financeapp.listener;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.ealvarenga.financeapp.DAO.UserDAO;
import com.ealvarenga.financeapp.helper.CryptographHelper;
import com.ealvarenga.financeapp.model.User;
import com.mobsandgeeks.saripaar.Validator;


/**
 * Created by ealvarenga on 24/11/17.
 */

public class SignUpListener implements View.OnClickListener {

    private Context ctx;
    private Validator v;
    private EditText email;
    private EditText password;
    private EditText name;

    public SignUpListener(Context ctx, Validator v) {
        this.ctx = ctx;
        this.v = v;
    }

    public String getEmail() {
        return email.getText().toString();
    }

    public SignUpListener setEmail(EditText email) {
        this.email = email;
        return this;
    }

    public String getPassword() {
        return password.getText().toString();
    }

    public SignUpListener setPassword(EditText password) {
        this.password = password;
        return this;
    }

    public String getName() {
        return this.name.getText().toString();
    }

    public SignUpListener setName(EditText name) {
        this.name = name;
        return this;
    }

    @Override
    public void onClick(View view) {
        this.v.validate();
    }
}
