package com.ealvarenga.financeapp.model;

import java.io.Serializable;
import java.time.DateTimeException;
import java.util.Calendar;
import java.util.Date;

/**
 * Created by ealvarenga on 24/11/17.
 */

public class Task implements Serializable {

    private String name;
    private String description;
    private Calendar dateStart;
    private Calendar dateEnd;
    private long taskId;

    public Task(String name, String description, Calendar dateStart, Calendar dateEnd) {
        if(dateStart.getTimeInMillis() > dateEnd.getTimeInMillis()) {
            throw new IllegalArgumentException("Starting date must be smaller than ending date");
        }

        this.dateStart = dateStart;
        this.dateEnd = dateEnd;
        this.description = description;
        this.name = name;
    }

    public Task(String name, String description) {
        this.name = name;
        this.description = description;
    }

    public Task() {}

    public String getName() {
        return name;
    }

    public Task setName(String name) {
        this.name = name;
        return this;
    }

    public String getDescription() {
        return description;
    }

    public Task setDescription(String description) {
        this.description = description;
        return this;
    }

    public Calendar getDateStart() {
        return dateStart;
    }

    public Task setDateStart(Calendar dateStart) {
        this.dateStart = dateStart;
        return this;
    }

    public Calendar getDateEnd() {
        return dateEnd;
    }

    public Task setDateEnd(Calendar dateEnd) {
        this.dateEnd = dateEnd;
        return this;
    }

    public long getTaskId() {
        return taskId;
    }

    public Task setTaskId(long taskId) {
        this.taskId = taskId;
        return this;
    }
}
