//James Cooks u21654680
// ArticleList.js
import React, { useState } from 'react';
import PropTypes from 'prop-types';
import Article from './Article';
import DateForm from './DateForm'; // Import the DateForm component

const ArticleList = ({ articles }) => {
  const [currentDate, setCurrentDate] = useState('2023/09/03');

  const handleDateChange = (newDate) => {
    setCurrentDate(newDate);
  };

  const filteredArticles = articles.filter((article) => article.date === currentDate);

  return (
    <div>
      <DateForm onDateChange={handleDateChange} />
      {filteredArticles.length > 0 && (
        <div>
          <h2>Articles on {currentDate}</h2>
          <div className="row">
            {filteredArticles.map((article, index) => (
              <div key={index} className="col-md-4">
                <Article article={article} />
              </div>
            ))}
          </div>
        </div>
      )}
    </div>
  );
};

ArticleList.propTypes = {
  articles: PropTypes.arrayOf(
    PropTypes.shape({
      name: PropTypes.string.isRequired,
      description: PropTypes.string.isRequired,
      date: PropTypes.string.isRequired,
    })
  ).isRequired,
};

export default ArticleList;
