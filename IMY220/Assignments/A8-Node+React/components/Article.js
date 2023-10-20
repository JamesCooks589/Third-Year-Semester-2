// Article.js
import React from 'react';

const Article = ({ article }) => {
  return (
    <div className="card mb-3">
      <div className="card-header">
        <h3>{article.name}</h3>
      </div>
      <div className="card-body">
        <p className="card-text"><b>Description: </b>{article.description}</p>
        <p className="card-text"><b>Date: </b>{article.date}</p>
      </div>
    </div>
  );
};

export default Article;
