package com.ealvarenga.financeapp.model;

import com.ealvarenga.financeapp.helper.CryptographHelper;

import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/**
 * Created by ealvarenga on 24/11/17.
 */

public class User {

    private String email;
    private String password;
    private String name;
    private long userId;

    public User(String email, String password, String name) {
        this.email = email;
        this.password = CryptographHelper.getMD5(password);
        this.name = name;
    }

    public User() {}

    public String getEmail() {
        return email;
    }

    public User setEmail(String email) {
        this.email = email;
        return this;
    }

    public String getPassword() {
        return password;
    }

    public User setPassword(String password) {
        this.password = CryptographHelper.getMD5(password);
        return this;
    }

    public long getUserId() {
        return userId;
    }

    public User setUserId(long userId) {
        this.userId = userId;
        return this;
    }

    public String getName() {
        return name;
    }

    public User setName(String name) {
        this.name = name;
        return this;
    }
}
